#include <iostream>

class test {
public:
    int data[10];
};

int main()
{
    test ttt;
    for(int it = 0;it < 10;++it)
    {
        std::cout << ttt.data[it] << std::endl;
    }
}
