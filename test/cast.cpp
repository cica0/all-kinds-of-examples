#include <iostream>

using namespace std;
class base {
public:
    base();
    ~base();
//    virtual ~base();
};

class derive : public base {
public:
};

void const_cast_test()
{
    const int a = 1;
    int *b = const_cast<int *>(&a) ;
    cout <<  ","<< *b << endl;
}

//void dynamic_cast_test()
//{
//    base *a = new base ;
//    derive *b = dynamic_cast<derive *>(a);
//}

void static_cast_test()
{
    int base = 1;
    int *b = static_cast<int *>(&base) ;
    cout <<  ","<< *b << endl;
}


void reinpreter_cast_test()
{
    int aa = 1;
    int *a = &aa;
    double *b = reinterpret_cast<double *>(a) ;
    cout << *a << "," << *b;
}

int main()
{
//reinpreter_cast_test();
static_cast_test();
}
