#include <iostream>

#include "rotation.h"

using std::cout;
using std::endl;

int main()
{
    Rotation rr;
    string s = "abcdefg";
    int rotate_num = 3;
//    rr.rotate1(s, 4);
    rr.rotate2(s, 4);
    cout << s << endl;
}
