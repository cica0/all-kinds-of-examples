#include <iostream>
#include <functional>

int add (int a)
{
    return a;
}

int add (int a, int b)
{
    return a+b;
}

int main()
{
//    auto result = std::bind(&add, std::placeholders::_2, std::placeholders::_1);
//    std::cout << result(4,4) << std::endl;
    int a= 1;
    int b =2;    
    std::cout << add(a,b) << std::endl;
    return 0;
}
