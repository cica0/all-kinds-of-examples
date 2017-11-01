#include <iostream>

class baseNewDelete {
public:
    static void * operator new(std::size_t size) throw (std::bad_alloc)
    {return ::operator new(size);}
    static void operator delete(void * pMemory) throw ()
    {return ::operator delete(pMemory);}
};

class myNewDelete : public baseNewDelete{
public:
    static void* operator new(std::size_t size,int a)
    {return ::operator new(size);}
    static void operator delete(void *pMemory,int a)
    {::operator delete(pMemory);}
    using baseNewDelete::operator new;
    using baseNewDelete::operator delete;
};

int main()
{
    myNewDelete *temp = new myNewDelete;
    delete(temp);
    return 0;
}
