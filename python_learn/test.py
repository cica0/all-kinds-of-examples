#!encoding=utf-8

import redis

class Database:  
    def __init__(self):  
        self.host = 'localhost'  
        self.port = 3456  
        #self.port = 6379  

    def write(self,website,city,year,month,day,deal_number):  
        try:  
            key = '_'.join([website,city,str(year),str(month),str(day)])  
            val = deal_number  
            r = redis.StrictRedis(host=self.host,port=self.port)  
            r.set(key,val)  
        except Exception, exception:  
            print exception  

    def read(self,website,city,year,month,day):  
        try:  
            key = '_'.join([website,city,str(year),str(month),str(day)])  
            r = redis.StrictRedis(host=self.host,port=self.port)  
            value = r.get(key)  
            print value  
            return value  
        except Exception, exception:  
            print exception  

if __name__ == '__main__':  
    db = Database()  
    db.write('meituan','beijing',2013,9,1,8000)  
    db.read('meituan','beijing',2013,9,1)  
