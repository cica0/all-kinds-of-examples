#include <iostream>
#include <string>
#include <sys/time.h>

//使用宏而不是函数可以把所在的行号打印出来，否则是函数的行号
#define printf0(message) \
    printf("[%s:%d]%s!\n", __FILE__, __LINE__,message);

enum TraceLevel {
    Normal,
    Warning,
    Error
};

void printf1(TraceLevel level,const char *message) {
    const char *levelstring[] = {"Normal: ", "Warning: ", "Error: "};
    char ms[50];
    sprintf(ms, "%s %s", levelstring[level], message);
    printf0(ms);
}

int main()
{
//    此处应该添加一个时间
//    printf("%s %s %d i am a message!\n", gettimeofday(), __FILE__, __LINE__);
//    printf0("i am a message!");
    printf1(TraceLevel::Normal, "i am a normal message!");
    return 0;
}
