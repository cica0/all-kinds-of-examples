#include <iostream>
#include <boost/noncopyable.hpp>

//继承了noncopyable则不能使用拷贝构造函数和赋值操作
//否则编译不过
class myclass : public boost::noncopyable
{
public:
    myclass() {};
    myclass(int i) {};
};

int main() {
    myclass cl1();
    std::cout << "ok" << std::endl;
    myclass cl2(2);
    std::cout << "ok" << std::endl;
//    myclass cl3(cl1);
//    std::cout << "ok" << std::endl;
//    myclass cl4(cl2);
//    std::cout << "ok" << std::endl;
}
