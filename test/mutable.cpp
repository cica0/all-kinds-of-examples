#include <iostream>

class Test {
public:
    void setValue(int v) {
        value = v;
    }
    int getValue() const {
        value += 1;
        return value;
    }
private:
    mutable int value;
};

int main()
{
    Test ttt;
    ttt.setValue(1);
    std::cout << ttt.getValue() << std::endl;
}

