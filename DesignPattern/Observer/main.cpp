#include <iostream>
#include "Observer.h"
#include "Subject.h"

using namespace std;

int main()
{
    Subject *sub = new Subject();
    Observer *ob1 = new Observer(sub);
    Observer *ob2 = new Observer(sub);
    sub->patch(ob1);
    sub->patch(ob2);
    sub->setValue(1);
    sub->notify();
    sub->depatch(ob2);
    sub->setValue(2);
    sub->notify();

    free(sub);
    free(ob1);
    free(ob2);
    return 0;
}
