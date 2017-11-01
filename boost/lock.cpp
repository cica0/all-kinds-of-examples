#include <iostream>
#include <boost/thread.hpp>
#include <boost/atomic.hpp>
using namespace std;

boost::mutex mutex_;
int a = 0;
//如果是两个线程在不加锁的情况下，同时对一个变量进行操作
//两个线程可能会同时将变量读入自己的内存中，操作后返回
//所以结果不一定会是预期中的
//如果使用atomic，则确保一个线程操作之后再进行第二个线程的操作
//确保是多线程安全的，无需加锁可以直接使用
//boost::atomic<int> a(0);

void add_a(void) {
//    boost::lock_guard<boost::mutex> guard(mutex_);
    for(int i =0;i<10;i++)
    {
        cout << "a=" << a << endl;
        a=a+100;
    }
}

void minus_a(void) {
//    boost::lock_guard<boost::mutex> guard(mutex_);
    for(int i=0; i<9; i++)
    {
        cout << "a=" << a << endl;
        a--;
    }
}

int main()
{
    boost::thread thread1(add_a);
    boost::thread thread2(minus_a);
    thread1.join();
    thread2.join();
//    cout << "a=" << a << endl;
    
    return 0;
}
