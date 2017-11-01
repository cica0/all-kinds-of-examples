#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/thread.hpp>
#include <boost/asio.hpp>
using namespace std;

//同步定时器
int main()
{
    boost::asio::io_service io;
    while(true)
    {
        boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
        t.wait();
        std::cout << "hello world" << std::endl;
    }
    return 0;
}

////异步定时器    
//void printhaha(const boost::system::error_code &ec) {
//    std::cout << "hello world" << std::endl;
////    std::cout<<boost::this_thread::get_id()<<std::endl;
//}
//
//int main()
//{
//    boost::asio::io_service io;
//    boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
//    boost::posix_time::ptime tomorrow_start(now.date());
//    tomorrow_start += boost::posix_time::time_duration(10,0,0);
//    cout << tomorrow_start << endl;
//    while(true)
//    {
//        boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
////        boost::asio::deadline_timer t(io, tomorrow_start);
//        t.async_wait(printhaha);
//    }
//    io.run();
//    return 0;
//}
