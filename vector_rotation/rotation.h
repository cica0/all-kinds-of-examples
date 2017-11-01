#ifndef ROTATION_H
#define ROTATION_H
#include <iostream>

using std::string;

class Rotation {
public:
    Rotation() {}
    ~Rotation() {}
    int rotate1(string& s, int rotate_num);
    int reverse(string& s, int start, int end);
    int rotate2(string& s, int rotate_num);

private:
};
#endif
