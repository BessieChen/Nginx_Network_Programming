#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal>

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
    
    printf("end\n");
    return 0;

}