#include <iostream>
#include <map>
using std::map;

void copy_map(map<int,int> &mp) {
    map<int,int> mp_s;
    mp_s[0] = 0;
    mp_s[1] = 1;
    mp = mp_s;
}

int main()
{

    map<int,int> mp;
    mp[0] = 100;
    mp[1] = 111;
    mp[2] = 222;
    copy_map(mp);
    std::cout << mp[0] << std::endl;
    std::cout << mp.size();
}
