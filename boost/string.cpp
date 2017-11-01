#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace boost::algorithm;
using namespace std;
//using namespace boost;
int main(){
    //string str("miss,you.just.call_to\002,say,I~love~you");
    string str("a\0011\002b\0012");
    vector<string> strVec;
    //split_regex(strVec, str, boost::regex("/002"));
    split(strVec, str, is_any_of("\002"));
    vector<string>::iterator it = strVec.begin();
    for (; it!=strVec.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
