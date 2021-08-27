#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/*
子进程即便是后来fork出来的, 也依旧知道父进程之前注册的信号函数
*/

void my_sig(int signo)
{
    printf("get signal\n");
}

int main(int argc, char *const *argv)
{
    pid_t pid;
    printf("begin\n");
    if(signal(SIGUSR1, my_sig) == SIG_ERR)
    {
        printf("register failed\n");
    }
    pid = fork();
    if(pid == -1)
    {
        printf("forked failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("child process, id == %d\n", getpid());
    }
    else{
        printf("father process, id == %d\n", getpid());
    }

    for(;;)
    {
        sleep(10);
        printf("this is id == %d\n", getpid());
    }
    
    printf("end\n");
    return 0;

}