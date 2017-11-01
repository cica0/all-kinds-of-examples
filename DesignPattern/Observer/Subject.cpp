#include "Subject.h"

Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::patch(Observer *observer) {
    observers_.push_back(observer);
}

void Subject::depatch(Observer *observer) {
    for(vector<Observer *>::iterator it = observers_.begin(); it!= observers_.end(); ++it) {
        if(*it == observer) {
            observers_.erase(it);
            return;
        }
    }
    return;
}

void Subject::notify(void) {
    for(vector<Observer *>::iterator it = observers_.begin(); it!= observers_.end(); ++it) {
        (*it)->update();
        cout << (*it)->getValue() << endl;
    }
}

int Subject::getValue(void) {
    return value_; 
}

void Subject::setValue(int value) {
    value_ = value; 
}
