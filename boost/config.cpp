#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

struct DemoConfig
{
    string    str1;
    int        int1;
};

//extern DemoConfig g_config_;
//typedef DemoConfig g_config_;

void ReadConfig(const char* configPath)
{
    po::options_description desc("Allowed options");
    DemoConfig g_config_;
    desc.add_options()
    ("str1", po::value<string>(&g_config_.str1), "str1")
    ("int1", po::value<int>(&g_config_.int1), "int1") ;

    std::ifstream settings_file(configPath);
    po::variables_map vm;
    po::store(po::parse_config_file(settings_file, desc), vm);
    po::notify(vm);
    cout << g_config_.str1 << endl;
    cout << g_config_.int1 << endl;
}

int main()
{
    string config_file = "config.txt";
    ReadConfig(config_file.c_str());
    return 0;
}
