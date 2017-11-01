#ifndef REDIS_REDISSERVER_H
#define REDIS_REDISSERVER_H

#include <iostream>
#include <string>

#include "hiredis/hiredis.h"
#include "glog/logging.h"
#include "gflags/gflags.h"

using std::string;
using std::vector;

class RedisServer {
public:
    RedisServer(string ip="localhost", int port=6379, struct timeval timeout = {5, 500000}):ip_(ip), port_(port), timeout_(timeout), pRedisContext_(NULL) {}
//    RedisServer() : RedisServer("localhost", 6379) {}
    ~RedisServer();
    int Connect();
    int Append(string);
    int GetReply(redisReply *reply);
    int GetIntReply(int &result);
    int GetStrReply(string &result);
    template <typename T>
    int GetArrayReply(vector<T> &result);

protected:

private:
    string ip_;
    int port_;
    struct timeval timeout_;
    redisContext *pRedisContext_;
};

#endif
