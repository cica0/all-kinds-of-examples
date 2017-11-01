#ifndef _OBSERVER_SUBJECT_H
#define _OBSERVER_SUBJECT_H

#include <vector>
#include <iostream>
#include "Observer.h"
using namespace std;

class Observer;

class Subject {
public:
    Subject();
    ~Subject();
    void patch(Observer *);
    void depatch(Observer *);
    void notify(void);
    int getValue(void);
    void setValue(int value);

private:
    int value_;
    vector<Observer *> observers_;

};

#endif   // #define _OBSERVER_SUBJECT_H
