#include <iostream>
//#include <cstdlib>
//#include <new>

using std::cout;
using std::endl;
using std::exit;

void no_memory() {
    cout << "failed to allocate memory\n";
    exit(0);       //参数为0为成功，否则为失败
    //这里一定要退出，否则会不断的递归调用，直到分配到正确的空间为止
}

int main()
{
    //new失败时调用的函数
    std::set_new_handler(no_memory);
    cout <<  "attemp to alloc 1G" << endl;
    char *p = new char [1024*1024*1024];
    cout << "ok" << endl;
    delete[] p;
    return 0;
}
