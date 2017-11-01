#include <iostream>
#include <glog/logging.h>
#include <gflags/gflags.h>

//#define NDEBUG
int main(int argc, char** argv)
{
    gflags::ParseCommandLineFlags(&argc, &argv, true);//gflags需要
    /*
    std::cout << "argc="<< argc << std::endl;
  for(int i = 0; i<argc; ++i)
      std::cout << "argv[" << i << "]:" << argv[i] << std::endl;
      */

    google::InitGoogleLogging(argv[0]);

    FLAGS_log_dir="./logs";
    std::cout << "log_dir = " << FLAGS_log_dir << std::endl; 
    //google::SetLogDestination(google::GLOG_INFO, "./logs/myInfo");
    std::cout << "enter into  glog"<< std::endl;
    LOG(INFO) << "hello,log!!";
    LOG(WARNING) << "hello, i am a warning!!";
    LOG(ERROR) << "i am an error" ;
//    LOG(FATAL) << "i am a fatal error" ;
    DLOG(INFO) << "i am a debug log ";

    google::ShutdownGoogleLogging();
    return 0;
}    
