#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
测试子进程的写时复制
*/

int g_test = 0;
int main(int argc, char *const *argv)
{
    pid_t pid;
    printf("begin\n");
    pid = fork();
    if(pid == -1)
    {
        printf("fork failed\n");
        exit(1);
    }
    if(pid == 0)
    {
        while(1)
        {
            g_test++;
            sleep(1);
            printf("id == %d, g_test = %d\n", getpid(), g_test);
        }
    }
    else 
    {
        while(1)
        {
            g_test++;
            sleep(5);
            printf("id == %d, g_test = %d\n", getpid(), g_test);
        }
    }
    printf("end\n");
    return 0;
}