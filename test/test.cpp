#include <iostream>
#include <map>
#include <tuple>
#include <functional>
#include <cstdlib>
using std::endl;
using std::cout;

class tt {
public:
    tt(){};
    inline ~tt(){};
};

inline void foo(char a)
{
    std::cout << "enter into foo(char)" << std::endl;
}
int test(void)
{
    int i = 0; 
    return i = 2 - 1;
}
//void foo(int a)
//{
//    std::cout << "enter into foo(int)" << std::endl;
//}
//
void bar()
{
    foo('a');
    test();
} 
//void foo(char a)
//{
//    std::cout << "enter into foo(char)" << std::endl;
//}
class B {
public:
    virtual void f()  const;
};
class D : public B {
public:
   virtual void f() ;
};
std::tuple<int, int, int> get_int(int id) {
    return std::make_tuple(1,1,1);
}
struct holder{
    int get_double()
    {
        return 3;
    }
};
int main()
{
//    bar();
//    int *p=NULL ;
//    int c = *p;
//    printf("\n [%d]\n", c); 
//    return 0;
//    int temp = 10000000;
//    short int i = temp;
//    sint32 aaa = 1;
//    cout << i << endl;
//    std::map<int,int> mp;
//    mp[0] = 1;
//    cout << test() << endl;
     
//    int a,b,c;
//    std::tie(a, b, c) = get_int(1);
//    std::cout << a << "\n" << b << "\n" << c << "\n";
//    holder h;
//    auto trip = std::mem_fn(&holder::get_double);
//    std::cout << trip(h);
}
