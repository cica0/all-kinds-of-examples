#include <iostream>
#include <gperftools/profiler.h>

void func1()
{
    int i = 0;
    while(i<10000) {
        ++i;
    }
}

void func2()
{
    int i = 0;
    while(i<20000) {
        ++i;
    }
}

void func3()
{
    for(int i = 0; i<10000; ++i) {
        func1();
        func2();
    }
}

int main()
{
    ProfilerStart("test.prof");
    func3();
    ProfilerStop();

    return 0;
}
