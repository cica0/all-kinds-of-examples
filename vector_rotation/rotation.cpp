#include "rotation.h"

int Rotation::rotate1(string& s, int rotate_num) {
    if (s.size() == 0)
        return 0;
    if (rotate_num > s.size())
        return -1;
    while(rotate_num > 0) {
        rotate_num--;
        char temp = s[0];
        int i = 0;
        while(i<s.size()-1) {
            s[i] = s[i+1];
            ++i;
        }
        s[i] = temp;
    }
    return 0;
}

int Rotation::reverse(string& s, int start, int end) {
    if(start > end)
        return -1;
    char temp;
    while(start < end) {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp; 
        ++start;
        --end;
    }
    return 0;
}

int Rotation::rotate2(string& s, int rotate_num) {
    if (s.size() == 0)
        return 0;
    if (rotate_num > s.size())
        return -1;
    reverse(s, 0, rotate_num-1);
    reverse(s, rotate_num, s.size()-1);
    reverse(s, 0, s.size()-1);
    return 0;
}
