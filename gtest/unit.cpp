#include <iostream>
#include <assert.h>

class Adder {
public:
    int add(int a, int b){
        return a+b;
    }
};

/*
class TestAdder : Adder{
public:
    void TestSum() {
        Adder* adder = new Adder();
        assert(adder->add(1, 1) == 2);
        assert(adder->add(-1, 1) == 0);
        assert(adder->add(1234, 988) == 2222);
        assert(adder->add(-1, -2) == -8);
    }
};

int main()
{
    TestAdder unit_test;
    unit_test.TestSum();
}
*/
