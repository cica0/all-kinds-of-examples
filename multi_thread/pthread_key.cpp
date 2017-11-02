#include <iostream>
#include <pthread.h>
#include <boost/thread.hpp>

using namespace std;
pthread_key_t key;
pthread_once_t key_once = PTHREAD_ONCE_INIT;

struct mem_load {
    int i;
    float f;
};

void my_thread1()
{
    struct mem_load data;
    data.i = 10;
    data.f = 0.4;
    pthread_setspecific(key, &data);
    struct mem_load *data_tmp = (struct mem_load *)pthread_getspecific(key);
    cout << "in thread1 data.i:" << data_tmp->i << endl;
    cout << "in thread1 data.f:" << data_tmp->f << endl;
}

void my_thread2()
{
    int aaa  = 101010;
    pthread_setspecific(key, &aaa);
    int* bbb = (int *)pthread_getspecific(key);
    cout << "the data in thread2 is:" << *bbb << endl;
}

void make_key() {
    int ret = pthread_key_create(&key, NULL);
    cout << "ret is:" << ret << endl;
}

int main()
{
    boost::thread thread1(my_thread1);
    boost::thread thread2(my_thread2);
    pthread_once(&key_once, make_key);
    thread1.join();
    thread2.join();
    return 0;
}
