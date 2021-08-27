#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

/*
1. 一旦写了fork()创建子进程, 父进程就要注册 SIGCHLD 的信号处理函数
    否则子进程被杀死变为zombie进程, 父进程就无法获得子进程的一些信息{例如计算结果}
2. 处理需要 waitpid(), 记得 #include <sys/wait.h>
3. 有意思的bug, case SIGCHLD 后面不能直接跟声明 pid_t pid = xxx; 否则报错:  a label can only be part of a statement and a declaration is not a statement
*/

void mysig(int signo)
{
    int state;
    switch(signo)
    {
        case SIGUSR1:
            printf("sigusr1\n");
            break;
        case SIGCHLD:
            printf("sigchild\n");
            pid_t pid = waitpid(-1, &state, WNOHANG);
            printf("state == %d\n", state);
            if(pid == 0)
            {
                return;
            }
            else if(pid == -1)
            {
                return;
            }
            return;
            break;
        default:
            break;
    }
    return;
}
int main(int argc, char *const *argv)
{
    pid_t pid;
    printf("begin\n");
    
    if(signal(SIGUSR1, mysig) == SIG_ERR)
    {
        printf("err\n");
        exit(1);
    }
    if(signal(SIGCHLD, mysig) == SIG_ERR)
    {
        printf("err2\n");
        exit(1);
    }

    pid = fork();
    if(pid == -1)
    {
        printf("err3\n");
        exit(1);
    }

    for(;;)
    {
        sleep(10);
        printf("id == %d\n", getpid());
    }

    printf("end\n");
    return 0;
}