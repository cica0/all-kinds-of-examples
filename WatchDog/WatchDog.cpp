/************************************************
 * 该例程讲解Linux软件看门狗的优雅编写方法
 *
 * 编写WatchDog有很多种方式：
 * a.一个WatchDog.sh脚本程序
 * b.一个WatchDog.exe可执行程序
 * c.一个可执行程序里面包含WatchDog
 *
 * 本例程就是使用的c方式，通过父进程监控子进程的运行状态来实现的
 * 其中父进程就是子进程（具体的任务进程）的WatchDog
************************************************/
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
using namespace std;
//
//void childProcessFunc() {
//    int i = 0;
//    while (true) {
//        ++i;
//        printf("i: %d, pid: %d, ppid: %d\n", i, getpid(), getppid());
//        if (i == 10) {
//            // 子进程主动结束
//            //exit(0);
//            char* p = NULL;
//            *p = 1;
//        }
//        sleep(5);
//    }
//}
//
//void forkChildProcess(int signal) {
//    cout << "enter into forlchildprocess signal is:" << signal << endl;
//    int status = 0;
//    // 等待子进程中断或终止，释放子进程资源
//    // 否则死掉的子进程会变成僵尸进程
//    int pid = wait(&status);
//    if (pid < 0)
//    {
//        printf("error: %s\n", strerror(errno));
//        return;
//    }
//
//    // 如果子进程是由于某种信号退出的，捕获该信号
//    if (WIFSIGNALED(status))
//    {
//        int signalNum = WTERMSIG(status);
//        printf("Child process was killed by signal num: %d\n", signalNum);
//    }
//
//    // 检测是否生成了core文件
//    if (WCOREDUMP(status))
//    {
//        printf("Child process core dump file generated\n");
//    }
//
//    // 等待3秒钟重新启动子进程
//    sleep(3);
//
//    pid = fork();
//    if (pid == 0)
//    {
//        printf("Fork new child process\n");
//        childProcessFunc();
//    }
//}
//
//bool initWatchDog()
//{
//    int pid = fork();
//    if (pid) {
//        // 父进程一直监视子进程的运行状态
//        while (true) {
//            // 捕获子进程结束信号
//            assert(signal(SIGCHLD, forkChildProcess) != SIG_ERR);
//            // 父进程挂起，当有信号来时被唤醒
//            pause();
//        }
//    }
//    else if (pid < 0) {
//        return false;
//    }
//    return true;
//}
//
//int main() 
//{
//    cout << "Main pid:" << getpid() << endl ;
//    // 初始化看门狗进程
//    bool ret = initWatchDog();
//    if (!ret) {
//        printf("Init watch dog failed\n");
//        return 1;
//    }
//    printf("Init watch dog success...\n");
//    // 运行子进程代码
//    childProcessFunc(); 
//    return 0;
//}
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>

bool initWatchDog();
void childProcessFunc() {
    printf ("enter into childProcessFunc\n");
    int i = 0;
    while (true) {
        ++i;
        printf("i: %d, pid: %d, ppid: %d\n", i, getpid(), getppid());
        if (i == 10) {
            // 子进程主动结束
            //exit(0);
            char* p = NULL;
            *p = 1;
        }
        sleep(1);
    }
}

void proc_exit(int)
{
    union wait wstat;
    printf ("enter into proc_exit\n");
    pid_t   pid;

    while (true) {
        pid = wait3 (&wstat, WNOHANG, (struct rusage *)NULL );
        if (pid == 0)
            return;
        else if (pid == -1)
            return;
        else {
            printf ("Return code: %d\n", wstat.w_retcode);
//            initWatchDog();
        }
    }
}

void forkChildProcess(int signal);
bool initWatchDog()
{
    printf ("enter into initWatchDog\n");
//    signal (SIGCHLD, proc_exit);
    signal (SIGCHLD, forkChildProcess);
    int pid = fork();
    if (pid) {
        pause();
    }
    else if (pid < 0) {
        return false;
    }
    childProcessFunc(); 
    return true;
}
void forkChildProcess(int signal) {
    cout << "enter into forlchildprocess signal is:" << signal << endl;
    int status = 0;
    // 等待子进程中断或终止，释放子进程资源
    // 否则死掉的子进程会变成僵尸进程
    int pid = wait(&status);
    if (pid < 0)
    {
        printf("error: %s\n", strerror(errno));
        return;
    }

    // 如果子进程是由于某种信号退出的，捕获该信号
    if (WIFSIGNALED(status))
    {
        int signalNum = WTERMSIG(status);
        printf("Child process was killed by signal num: %d\n", signalNum);
    }

    // 检测是否生成了core文件
    if (WCOREDUMP(status))
    {
        printf("Child process core dump file generated\n");
    }

    // 等待3秒钟重新启动子进程
    sleep(3);

    pid = fork();
    if (pid == 0)
    {
        printf("Fork new child process\n");
        childProcessFunc();
    }
}


int main ()
{
    printf("Main pid:%d\n",getpid());
    // 初始化看门狗进程
    bool ret = initWatchDog();
    if (!ret) {
        printf("Init watch dog failed\n");
        return 1;
    }
    printf("Init watch dog success...\n");
    // 运行子进程代码
//    childProcessFunc(); 
    return 0;
}
