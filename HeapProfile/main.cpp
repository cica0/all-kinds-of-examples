#include <iostream>
#include "google/heap-profiler.h"

void test2()
{
    int i = 100;
    while(i--) {
        char *buf = new char[1024*1024];
    }
}
void test1()
{
    int i = 100;
    while(i--) {
        char *buf = new char[1024*1024];
    }
    test2();
}


int main()
{
    HeapProfilerStart("./test.log");
    int i = 100;
    while(i--) {
        char *buf = new char[1024*1024];
    }
    test1();
//    test2();
    HeapProfilerStop();
    return 0;
}
