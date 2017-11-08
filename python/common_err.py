# -*- coding: UTF-8 -*- #

#只有在第一次定义此函数的时候，才会生成默认参数，之后每次都使用之前的参数
def err_1(bar=[]):
    bar.append("bza")
    return bar

def solution_1(bar=[]):
    if bar is not None:
        bar = []
    bar.append("bza")
    return bar

def test_1():
    print err_1()
    print err_1()
    print err_1()
    print err_1()
    print err_1()
    print solution_1()
    print solution_1()
    print solution_1()
    print solution_1()
    print solution_1()


#如果类中没有某个变量，去它的基类中查找
#例如如果C中的x没有使用（赋值）这种，则引用基类的x
#如果C中的x被使用，则为独立的
class A (object):
    x = 1
class B (A):
    pass
class C (A):
    pass

if __name__ == "__main__" :
    #test_1()
    print A.x ,B.x ,C.x
    B.x = 6
    print A.x ,B.x ,C.x
    A.x = 4
    print A.x ,B.x ,C.x
