#include "Observer.h"

Observer::Observer(Subject *sub) {
    subject_ = sub;
}

Observer::~Observer() {
}

void Observer::update() {
    if(subject_ != NULL)
        subject_value_ = subject_->getValue();
}

int Observer::getValue(void) {
    return subject_value_;
}

void Observer::look(Subject *subject) {
    subject_ = subject;
}

