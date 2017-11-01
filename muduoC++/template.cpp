#include <iostream>

using namespace std;

template <typename T, typename F>
class class_template {
public:
    T a;
    F b;
};


//模板的全特化
template <>
class class_template<int,int> {
public:
    int a=-1;
    int b=-1;
};

//模板的偏特化
template <typename T>
class class_template<int, T> {
public:
    int a=0;
    T b;
};
int main()
{ 
    class_template<int,double> A;
    cout << "A.a:" <<  A.a << std::endl <<"A.b:" <<  A.b << std::endl;
    class_template<int,int> B;
    cout << "B.a:" <<  B.a << std::endl << "B.b:" <<  B.b << std::endl;
    class_template<bool,int> C;
    cout << "C.a:" <<  C.a << std::endl << "C.b:" <<  C.b << std::endl;
}
