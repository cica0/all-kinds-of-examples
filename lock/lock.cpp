#include <iostream>
#include <pthread.h>
#define NUM_THREADS 3

using std::cout;

//mutex m;
int sh = 8;

void *f(void *argv)
{
//    unique_lock<mutex> lck(m);
    cout << "enter into f";
    sh += 10; 
    cout << "sh = " << sh;
    return (void *)NULL;
}


int main()
{
    pthread_t tid[NUM_THREADS];
    cout << "enter into main" << std::endl;
    int ret = 0;
    for(int i = 0; i<NUM_THREADS; ++i)
    {
        cout << "i is " << i << std::endl;
        ret = pthread_create(&tid[i], NULL, f, NULL);
        cout << "ret is " << ret << std::endl;
        if(ret != 0)
            cout << "pthread_create error";
    }
    return 0;
}
