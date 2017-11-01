#!encoding=utf-8

import redis

class Database:
    def __init__(self, host, port):
        self.host = host
        self.port = port

    def connect(self):
        return redis.StrictRedis(self.host, self.port)

if __name__ == '__main__':
    print "enter into main"
    db = Database("127.0.0.1", 6379)
    print db.host
    print db.port
    r = db.connect()
    r.set("harbin","0451")
    print r.get("harbin")
