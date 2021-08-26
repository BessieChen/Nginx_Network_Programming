#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *const *argv)
{
    pid_t pid;
    printf("begin\n");
    pid = fork();
    if(pid == -1)
    {
        printf("something goes wrong.\n");
        exit(1);
    }
    else if(pid == 0)
    {
        // setsid();
        for(;;)
        {
            printf("child process\n");
            sleep(1);
        }
    }
    else{
        for(;;)
        {
            printf("father process\n");
            sleep(1);
        }
    }
    return 0;
}