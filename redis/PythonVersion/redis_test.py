#!/user/bin/env python
# encoding:utf-8

import sys 
sys.path.append('/home/chang/study/python/lib/redis-py')
import redis
import time 
#import json

class Database:  
    def __init__(self):  
        self.host = 'localhost'  
        self.port = 6930  

#    def write(self,key,val):  
#        try:  
#            r = redis.StrictRedis(host=self.host,port=self.port)  
#            r.set(key,val)  
#        except Exception, exception:  
#            print exception  

    def read(self,key):  
        try:  
            r = redis.StrictRedis(host=self.host,port=self.port)  
            value = r.get(key)  
            print value  
            return value  
        except Exception, exception:  
            print exception  

if __name__ == '__main__':  
    db = Database()  
    if len(sys.argv)>1:
        docids_key = 'push_news_ids_'+sys.argv[1]
    else: 
        docids_key = 'push_news_ids_' + time.strftime("%Y%m%d")
    print docids_key
    db.read(docids_key)  
