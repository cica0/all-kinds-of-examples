# -*- coding: UTF-8 -*- #
#print "hello,world"
#name = raw_input()
#print name
#
#names = ['lily','lucy','bell']
#for name in names:
#    print name
#    
#def hello(name):
#    return 'Hello, ' + name + '!'
#
#print hello("liuchang")    

#python中如果想要定义私有函数，使用双下划线+私有函数名，无法在类外提供访问
#如果想要在类外进行访问，使用单下划线+类名+双下划线+私有函数名,不建议这么使用
#class Secret:
#    def __inaccessible(self):   
#        print "you can not see me"
#    def accessible(self):
#        print "you can see me"
#        self.__inaccessible()
#
#s = Secret()        
#s._Secret__inaccessible()
#s.accessible()

#python与C++不同的是，使用成员函数对成员变量进行改变的时候，py对所有实例化的对象都进行更改
#class MemberCounter:
#    members = 0
#    def init(self):
#        MemberCounter.members += 1
#
#m1 = MemberCounter()
#m1.init()
#print m1.members
#m2 = MemberCounter()
#m2.init()
#print m2.members

#class Filter:
#    def init(self):
#        self.blocked = []
#    def filter(self,sequence):
#        return [x for x in sequence if x not in self.blocked]
#    def printblocked(self):
#        print self.blocked
#class SPAMFilter(Filter):
#    def init(self):
#        self.blocked = ['SPAM']
#f = Filter()
#f.init()
#print f.filter([1,2,3])
#s = SPAMFilter()
#s.init()
#print s.filter(['SPAM','SPAM','SPAM','a','b','c'])
##判断第一个参数是否是第二个参数的子类
#print issubclass(SPAMFilter, Filter)
#print issubclass(Filter, SPAMFilter)
##判断第一个参数是否是第二个参数的实例
#print isinstance(s, SPAMFilter)
##判断第二个参数是否是第一个参数的方法
#print hasattr(Filter,"Filter")

##如果有异常会进入到except中，没有异常会进入到else中
##最后有没有异常都会进入到finally中
#try:
#    1/0
#except Exception,e:
#    print 'ivalid input:', e    
#else:
#    print "i am break"
#finally:
#    print 'i am finally'

#可以用是否是实例判断一个变量是否是一个类型
#if not isinstance(1, (int, long)):
#    raise TypeError
#else:
#    print "i am int or long"

#使用property可以将多个访问器方法合到一起，形成一个新属性
#property函数的顺序分别是（get，set，del）第四个参数不常用
#class Rectangle:
#    def __init__(self):
#        self.width = 0
#        self.height = 0
#    def setSize(self,size):
#        self.width, self.height=size    
#    def getSize(self):
#        return self.width, self.height
#    #size = property(getSize, setSize)
#    size = property()
#
#r = Rectangle()
#r.width = 10
#r.height = 20
#print r.width    
##这里传入的size应该是个元组
#r.setSize((100,200))
#print r.getSize()
##print r.size
#r.size = 10000
#print r.size

##staticmethod不需要表示自身对象的self和表示自身类的cls，直接使用类名.函数名
##classmethod 不需要表示自身对象的self，但是需要表示自身类的cls,直接使用类名.函数名
#class MyClass:
#    bar = 1
#    @staticmethod
#    def smeth():
#        print "i am smeth"
#
#    @classmethod
#    def cmeth(cls):
#        print "i am cmeth", cls.bar
#MyClass.smeth()
#MyClass.cmeth()

##迭代器测试，自动执行next，直到结束
#class TestIterator:
#    value = 0
#    def next(self):
#        self.value += 1
#        if self.value > 10:raise StopIteration
#        return self.value
#    def __iter__(self):
#        return self
#
#t = TestIterator()
#for i in t:
#    print i

##引入python库的时候，需要将路径加进去
##要作为库的python会生成后缀名为pyc的文件，类似于静态库的.a
##pprint提供更加智能的打印输出，需要包含库pprint
#import sys,pprint
#pprint.pprint (sys.path)
##sys.path.append("./")
#import hi
##如果当前python作为程序运行的时候，走下面的流程
##如果是作为py库导入的话，下面的流程不走
##如果不加if __name__ == '__main__':这一句，作为库导入的话也会走下面的流程
#if __name__ == '__main__':
#    print "i am in main"
#    hi.hi()

##可以将多个模块放在一起，作为一个包使用
#import drawing
##走到这里的时候，__init__ 中的内容可用，drawing和colors模块不可用
#import drawing.colors
##走到这里的时候，colors模块可用,但是需要通过全名drawing.colors使用
#from drawing import shapes
##走到这里的时候，可以直接使用shapes进行使用

#import hi
##此函数打印出上面这个库中的所有的函数
#print dir(hi)
##下面的命令可以找到库文件在哪里，从而找到源代码
#print hi.__file__

##集合内的元素只能是不可变的值，而集合是可变的，所以集合内不能包含集合
##如果实在想要在集合内包含集合，使用frozenset(),代表不可变的集合
#a=set()
#b=set()
#a.add(frozenset(b))
#print a

##shffle的含义是将数组内的元素顺序打乱
##import库的时候，如果使用heapq中的heappush函数有3种import方法
##（1）import heapq，使用的时候，heapq.heappush（）
##（2）from heapq import *，使用的时候直接使用heappush（）
##（3）from heapq import heappush，使用的时候直接使用heappush（）    
##第三种方法最好，以防和其他库内函数有函数冲突
#from random import shuffle
#from heapq import heappush
#data = range(10)
#shuffle(data)
#print data
#heap=[]
#for n in data:
#    heappush(heap, n)
#print heap

#import random
##随机数产生0~1范围的随机实数
#print random.random()
##使用uniform(a,b)随机数产生a~b范围的随机实数
#print random.uniform(1,10)
##使用uniform(a,b)随机数产生a~b范围的随机整数
#print random.randrange(1,10)

##在文件中存储数据,类似于数据库的功能
#import shelve
#def store_person(db):
#    pid = raw_input('Enter unique ID number:')
#    person = {}
#    person['name'] = raw_input('Enter name:')
#    person['age'] = raw_input('Enter age:')
#    person['phone'] = raw_input('Enter phone:')
#    db[pid] = person
#
#def lookup_person(db):
#    pid = raw_input('Enter ID number:')
#    field = raw_input('What would you like to know?(name,age,phone) ')
#    field = field.strip().lower()
#    print field.capitalize()+':', db[pid][field]
#
#def print_help():
#    print "The avaliable commands are:"
#    print "store  : Stores information about a person"
#    print "lookup : lookup a person from ID number"
#    print "quit   : save changes and exit"
#    print "?      : print this message"
#
#def enter_command():
#    cmd = raw_input('Enter command (? for help):')
#    cmd = cmd.strip().lower()
#    return cmd
#
#def main():
#    database = shelve.open('database.dat')
#    try:
#        while True:
#            cmd = enter_command()
#            if cmd == 'store':
#                store_person(database)
#            if cmd == 'lookup':
#                lookup_person(database)
#            if cmd == '?':
#                print_help() 
#            elif cmd == 'quit':
#                return
#    finally:
#        database.close()
#
#if __name__ == '__main__' : main()

##使用正则表达式的search函数，可以在string中搜索pat匹配的正则字符串的位置
##使用match函数，只能匹配string中以pat开头的正则字符串的位置
#import re
#pat = 'p'
#string = 'ytpsshon'
#if re.search(pat, string):
#    print "search find it"
#if re.match(pat, string):
#    print "match find it"


