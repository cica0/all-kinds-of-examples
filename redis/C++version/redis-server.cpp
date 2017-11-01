#include "redis-server.h"

#include <iostream>
#include <string>

RedisServer::~RedisServer() {
    if(pRedisContext_ != NULL) {
        redisFree(pRedisContext_);
        pRedisContext_ = NULL; 
    }
}

int RedisServer::Connect() {
    pRedisContext_ = (redisContext*)redisConnectWithTimeout(ip_.c_str(), port_ ,timeout_ );
    if(!pRedisContext_ || pRedisContext_->err) {
        if (pRedisContext_) {
            LOG(ERROR)<< "connect fail:" << pRedisContext_->errstr;
            redisFree(pRedisContext_);
            pRedisContext_ = NULL; 
        } else {
            LOG(ERROR) << "connect error";
            return -1;
        }
    } else {
        LOG(INFO)<< "connect success";
        return 0;
    }
    return 0;
}

int RedisServer::Append(string append_str) {
    if(NULL == pRedisContext_) {
        LOG(ERROR) << "pRedisContext_ is NULL so can not append";
        return -1;
    }
    int err = redisAppendCommand(pRedisContext_, append_str.c_str());
    if(err) {
        LOG(ERROR) << "redisAppendCommand error";
        redisFree(pRedisContext_);
        pRedisContext_ = NULL; 
        return -1;
    }
}

int RedisServer::GetReply(redisReply **reply, string info) {
    if(NULL == pRedisContext_) {
        LOG(ERROR) << "pRedisContext_ is NULL so can not search";
        return -1;
    }
    *reply= (redisReply*)redisCommand(pRedisContext_, info.c_str());  //执行INFO命令
    if(*reply == NULL) {
        LOG(ERROR) << "the reply is null";
        return -1;
    } else if (*reply != NULL && (*reply)->type == REDIS_REPLY_ERROR) {
        freeReplyObject(*reply);
        *reply = NULL;
        LOG(ERROR) << "return redis reply error";
        return -1;
    }
    return 0;
}

int RedisServer::GetIntReply(int &result, string info) {
    redisReply *reply = NULL ;
    if (0 != RedisServer::GetReply(&reply, info)) {
        LOG(ERROR) << "GetReply error";
        return -1;
    }
    LOG(INFO) << "reply type is :" << reply->type;
    if (reply->type != REDIS_REPLY_INTEGER) {
        LOG(ERROR) << "type is not integer, don't use GetIntReply";
        return -1;
    }
    LOG(INFO) << "reply value is :" << reply->integer;
    result = reply->integer; 
    return 0;
}

int RedisServer::GetStrReply(string &result,string info) {
    redisReply *reply = NULL;
    if (0 != RedisServer::GetReply(&reply, info)) {
        LOG(ERROR) << "GetReply error";
        return -1;
    }
    LOG(INFO) << "reply type is :" << reply->type;
    if (reply->type != REDIS_REPLY_STRING) {
        LOG(ERROR) << "type is not string, don't use GetStrReply";
        return -1;
    }
//    LOG(INFO) << "reply value is :" << reply->str;
    result = reply->str;
    return 0;
}

template <typename T>
int RedisServer::GetArrayReply(vector<T> &result, string info) {
    redisReply *reply = NULL;
    if (0 != RedisServer::GetReply(&reply, info)) {
        LOG(ERROR) << "GetReply error";
        return -1;
    }
    LOG(INFO) << "reply type is :" << reply->type;
    if (reply->type != REDIS_REPLY_ARRAY) {
        LOG(ERROR) << "type is not array, don't use GetArrayReply";
        return -1;
    }
    LOG(INFO) << "reply element size is :" << reply->elements;
    for(int i = 0; i<reply->elements; ++i)
        result.push_back(reply->element[i]->str);
    return 0;
}

