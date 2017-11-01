#include <iostream>

#include "glog/logging.h"

#include "redis-server.h"

//最简单的redis使用
int simpleredis()
{
    struct timeval timeout = {2, 0};    //2s的超时时间
    redisContext *pRedisContext = (redisContext*)redisConnectWithTimeout("127.0.0.1", 6379, timeout);
    if ((NULL == pRedisContext) || (pRedisContext->err)) {
        if (pRedisContext) {
            std::cout << "connect error:" << pRedisContext->errstr << std::endl;
        } else {
            std::cout << "connect error: can't allocate redis context." << std::endl;
        }
        return -1;
    }
    redisReply *pRedisReply = (redisReply*)redisCommand(pRedisContext, "INFO");  //执行INFO命令
    std::cout << pRedisReply->str << std::endl;
    freeReplyObject(pRedisReply);   
}

//redis管道
int redispipe()
{    
    redisContext *rconn = NULL;
    struct timeval timeout = {5, 500000}; // 5.5 seconds
    rconn = redisConnectWithTimeout("127.0.0.1", 6379, timeout);
    if (rconn == NULL || rconn->err) {
      printf("redisConnectWithTimeout error : %s\n", (rconn ? rconn->errstr : "rconn is NULL"));
      if (rconn != NULL) redisFree(rconn);
      return -1;
    }

    int rec = 0;
    int opTime = time(NULL);
    rec = redisAppendCommand(rconn, "hset followings_leo ox %d", opTime);
    if (rec) {
      printf("[%d]redisAppendCommand error : %d\n", __LINE__, rec);
      redisFree(rconn);
      return -1;
    }

    rec = redisAppendCommand(rconn, "hset followers_ox leo %d", opTime);
    if (rec) {
      printf("[%d]redisAppendCommand error : %d\n", __LINE__, rec);
      redisFree(rconn);
      return -1;
    }

    redisReply *replys = NULL;
    rec = redisGetReply(rconn, (void**)(&replys));
    if (rec) {
      printf("[%d]redisGetReply error : %d\n", __LINE__, rec);
      redisFree(rconn);
      if (replys != NULL) freeReplyObject(replys);
      return -1;
    }

    if (replys != NULL && REDIS_REPLY_ERROR == replys->type) {
      freeReplyObject(replys);
      replys = NULL;
      printf("[%d] hset return  REDIS_REPLY_ERROR\n", __LINE__);
    }
    else if (replys == NULL) {
      printf("[%d] hset replys is NULL\n", __LINE__);
    }
    else {
      printf("[%d] replys-type = %d\n", __LINE__, replys->type);
      if (replys->type == REDIS_REPLY_INTEGER) {
        printf("[%d] hset success! return %ld\n", __LINE__, replys->integer);
      }
      else  {
        printf("[%d] hset error!\n", __LINE__);
      }
      
      freeReplyObject(replys);
      replys = NULL;
    }
    //////////////////获取第二条redis请求的回复
    rec = redisGetReply(rconn, (void**)(&replys));
    if (rec) {
      printf("[%d] redisGetReply error : %d\n", __LINE__, rec);
      redisFree(rconn);
      if (replys != NULL) freeReplyObject(replys);
      return -1;
    }

    if (replys != NULL && REDIS_REPLY_ERROR == replys->type) {
      freeReplyObject(replys);
      replys = NULL;
      printf("[%d] hset return  REDIS_REPLY_ERROR\n", __LINE__);
    }
    else if (replys == NULL) {
      printf("[%d] hset replys is NULL\n", __LINE__);
    }
    else {
      printf("[%d] replys-type = %d\n", __LINE__, replys->type);
      if (replys->type == REDIS_REPLY_INTEGER) {
        printf("[%d] hset success! return %ld\n", __LINE__, replys->integer);
      }
      else  {
        printf("[%d] hset error!\n", __LINE__);
      }
      
      freeReplyObject(replys);
      replys = NULL;
    }
    redisFree(rconn);
}


int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);
    google::ParseCommandLineFlags(&argc, &argv, true);
    FLAGS_log_dir = "./logs/";

    simpleredis();
    redispipe();
    google::ShutdownGoogleLogging();
}
