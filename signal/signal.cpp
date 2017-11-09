#include <stdio.h>  
#include <stdlib.h>  
#include "signal.h"  
#include "sys/types.h"  
#include "unistd.h"  
#include <pthread.h>  
  

static void* pthread_func_1 (void* data)    {    
    int i = 0;    
    for (; i < 6; i++)    {    
        printf ("This is pthread1!/n");    
        if (i == 2)    {    
            pthread_exit (0);    
        }    
        sleep (1);    
    }    
    return NULL;  
}    
   
void my_action(int signum, siginfo_t * info, void * myact)  
{ //信号的响应操作  
        printf("recive signal %d\n", signum);  
}  

void CreateSigAndBind(int Sig,void (*fun)(int signum, siginfo_t * info, void * myact))  
{  
    struct sigaction act; //创建新的信号  
    struct sigaction old_act; //用与记录旧的信号，当然你也可以不用记录  
  
    sigemptyset(&act.sa_mask);  
    act.sa_flags = SA_SIGINFO;  
    act.sa_sigaction = fun; //设置信号的响应操作  
  
    if(sigaction(Sig, &act, &old_act) < 0) { //开始创建信号  
            printf("install sigal error\n");  
            return ;  
    }  
}  
  
int main(int argc, char**argv)  
{  
    CreateSigAndBind(43,&my_action);  
    CreateSigAndBind(44,&my_action);  

    pthread_t pt_1 = 0; 
    int ret = pthread_create (&pt_1, NULL, pthread_func_1,NULL);    
    if (ret != 0)    {    
        perror ("pthread_1_create");    
    }    
  
    while(1) { //为了测试写的一个死循环  
        sleep(2);  
        printf("Now we wait for signal\n");  
    }  
    return 1 ;  
}  
