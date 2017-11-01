#include <gflags/gflags.h>

/*
DEFINE_bool(big_menu, true, "i am a comment of big_menu");
DEFINE_string(country, "China, Frech, German","i am a comment of country");

int main(int argc, char **argv)
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    return 0;
}
*/
// demo.cpp
#include <iostream>
#include <gflags/gflags.h>

using namespace std;

DEFINE_string(confPath, "test.conf", "program configure file.");
DEFINE_int32(port, 1111, "program listen port");
DEFINE_bool(debug, true, "run debug mode");

int main(int argc, char** argv)
{

    google::SetVersionString("1.1");
  //gflags::ParseCommandLineFlags(&argc, &argv, false);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
 
  cout << "argc= " << argc << endl;
  for(int i = 0; i<argc; ++i)
      cout << "argv[" << i << "]:" << argv[i] << endl;;
  cout << "confPath = " << FLAGS_confPath << endl;
  cout << "port = " << FLAGS_port << endl;

  if (FLAGS_debug) {
    cout << "run debug mode..." << endl;
  }
  else {
    cout << "run nodebug mode...." << endl;
  }

  cout << "oh succuss~~" << endl;

  gflags::ShutDownCommandLineFlags();
  return 0;
}
