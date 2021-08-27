#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
练习信号处理函数
*/
void my_sig(int signo)
{
    if(signo ==  SIGUSR1)
    {
        printf("1\n");
    }
    else if(signo == SIGUSR2)
    {
        printf("2\n");
    }
    else
    {
        printf("others\n");
    }
}

int main(int argc, char *const *argv)
{
    if(signal(SIGUSR1, my_sig) == SIG_ERR)
    {
        printf("register signal 1 failed\n");
    }
    else if(signal(SIGUSR2, my_sig) == SIG_ERR)
    {
        printf("register signal 2 failed\n");
    }

    for(;;)
    {
        int *p;
        p = (int*)malloc(sizeof(int));
        free(p);
    }
    printf("exit\n");
    return 0;
}