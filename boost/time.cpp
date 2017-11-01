#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
#include <string>

int main()
{
    boost::posix_time::ptime tick = boost::posix_time::microsec_clock::local_time();
//    int i = 100000;
//    while(i--)
//    {
//        std::cout << i << std::endl;
//    }
    boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
    boost::posix_time::time_duration diff = now - tick;
    std::cout << "diff is:" << diff << std::endl;
    std::cout << "now is:" <<now << std::endl;
//    std::string now_string = to_simple_string(now);
//    std::cout << "now_string is:" <<now_string << std::endl;
    boost::posix_time::ptime tomorrow_start(now.date());
    std::cout << "now date is:" << now.date()<< std::endl;
    std::cout << "tomorrow_start is:" <<tomorrow_start<< std::endl;
    return 0;
}
