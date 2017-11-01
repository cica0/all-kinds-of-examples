#ifndef _OBSERVER_OBSERVER_H
#define _OBSERVER_OBSERVER_H
#include "Subject.h"
#include <iostream>
class Subject;

class Observer {
public:
    Observer(Subject *);
    ~Observer();
    void update();
    int getValue(void);
    void look(Subject *);

private:
    Subject *subject_;
    int subject_value_;
};

#endif   // #define _OBSERVER_OBSERVER_H
