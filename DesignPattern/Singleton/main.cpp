#include <iostream>
#include "Singleton.h"

int main()
{
    int *mysingle = Singleton<int>::getInstance();
    int *mysingle2 = Singleton<int>::getInstance();

    std::cout << mysingle << std::endl;
    std::cout << mysingle2 << std::endl;
    return 0;
}
