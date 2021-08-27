#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/*
1. 如何屏蔽某个信号
2. 在终端关闭后, 如何能保证在这个终端运行的进程不被杀死, 用子进程setsid() 
*/

int main(int args, char *const *argv){
    // signal(SIGHUP, SIG_IGN);
    // setsid();
    printf("Hi there.\n");
    for(;;){
        sleep(1);
        printf("1s. \n");
    }
    printf("exit\n");
    return 0;
}