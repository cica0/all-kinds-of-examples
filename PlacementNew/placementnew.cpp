#include <iostream>
#include <new>

class Task {
public:
    int i;
    int test() { return 1;}
};

int main()
{
    char * buf = new char[sizeof(Task)];//申请空间
    Task *T= new(buf) Task;             //placement new构造函数 
    std::cout << T->test();             //使用
    T->~Task();                         //析构
    delete [] buf;                      //内存返回 

}
