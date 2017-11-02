#include <iostream>
#include <boost/thread.hpp>
#include <pthread.h>
using namespace std;

int sh = 8;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void my_mutex() {
    pthread_mutex_lock(&mutex);
    sh += 10; 
    cout << "sh = " << sh << std::endl;
    pthread_mutex_unlock(&mutex);
}

void my_cond() {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    sh += 10; 
    cout << "sh = " << sh << std::endl;
    pthread_mutex_unlock(&mutex);
}

void test_mutex() {
    boost::thread thread1(my_mutex);
    boost::thread thread2(my_mutex);
    boost::thread thread3(my_mutex);
    thread1.join();
    thread2.join();
    thread3.join();
}

void test_cond() {
    boost::thread thread1(my_cond);
    boost::thread thread2(my_cond);
    boost::thread thread3(my_cond);
    for(int i =0;i<3;++i) {
        sleep(3);           //这里如果不加sleep会造成死锁
        pthread_cond_signal(&cond);
    }
    thread1.join();
    thread2.join();
    thread3.join();
}

int main()
{
//    test_mutex();
    test_cond();
    return 0;
}
