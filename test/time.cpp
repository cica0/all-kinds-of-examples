#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

void dsptime(const struct tm * ptm)  {  
    cout << ptm->tm_year+1900 << "-"; 
    if(ptm->tm_mon+1 < 10)
        cout << "0";  
    cout << ptm->tm_mon+1 << "-" ;
    if(ptm->tm_mday < 10)
        cout << "0";  
    cout << ptm->tm_mday << endl;  
}  

int whichday(time_t *today, int nDay_before) {
    time_t myt= *today - nDay_before*24*3600;
    struct tm *local=localtime(&myt);  //获取当前系统时间  
    dsptime(local);   
    return 0;
}

 
int main() {
    time_t nowtime;  
    nowtime = time(NULL);    //获取日历时间  
//    struct tm *local = localtime(&nowtime);  //获取当前系统时间  
    for(int i =0; i<30;++i) {
        whichday(&nowtime,i);
    }
    return 0;  
}
