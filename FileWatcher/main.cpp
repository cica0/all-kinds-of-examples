#include <iostream>
#include "FileWatcher.h"


void update(int a) {
    std::cout << "updatehhhhhhhhhhhhhh" << std::endl;
}

int main()
{
    FileWatcher config_watcher;
    config_watcher.Watch("./config.txt",boost::bind(&update,1));
    sleep(100);
    return 0;
}
