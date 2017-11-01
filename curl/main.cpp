#include <iostream>

#include "curl/curl.h"

using std::cout;
using std::endl;

static size_t bodycallback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    cout << "enter into bodycallback" << endl;
    cout << "size is:" << size << endl;
    cout << "nmemb is:" << nmemb << endl;
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

static size_t headcallback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    cout << "enter into headcallback" << endl;
    cout << "size is:" << size << endl;
    cout << "nmemb is:" << nmemb << endl;
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    curl_global_init(CURL_GLOBAL_ALL);
    cout << "my curl version is:" << curl_version() << endl;
    static const char *bodyfilename = "body.out";
    static const char *headfilename = "head.out";

    CURLcode res;
    CURL *curl = curl_easy_init();
    if(curl) {
        //这里是想要获取的url地址
        curl_easy_setopt(curl, CURLOPT_URL, "www.example.com");

        FILE * bodyfile = fopen(bodyfilename, "wb");
        if(!bodyfile) {
            cout << "fopen bodyfile error" << endl;
            return -1;
        }
        FILE * headfile = fopen(headfilename, "wb");
        if(!headfile) {
            cout << "fopen headfile error" << endl;
            return -1;
        }

        //设置想要调用的body回调函数
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, bodycallback);
        //这里是将抓取结果写在pagefile所指的文件中
        //如果有CURLOPT_WRITEDATA而没有CURLOPT_WRITEFUNCTION则系统自动生成一个回掉函数
        //如果有CURLOPT_WRITEFUNCTION则调用自己定义的回调
        //如果自定义的回调没有写进文件，则不会写进文件
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, bodyfile);

        //保存http的head头部数据
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, headcallback);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, headfile);

        //在这里执行前面加进去的命令
        res = curl_easy_perform(curl);
        if(CURLE_OK == res) {
           char *ct = NULL;
           //这里获取抓取信息的content_type
           res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct); 
           if( CURLE_OK == res && ct)
               cout << "we received content_type :" << ct << endl;
        }
        fclose(bodyfile);
        fclose(headfile);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}
