#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
测试系统调用 write(), 其中 stdout_fileno 是屏幕的fd
*/

int main(int argc, char *const *argv)
{
    printf("begin\n");
    write(STDOUT_FILENO, "aaaaa", 5);
    while(1)
    {
        sleep(1);
    }
    printf("end\n");
    return 0;
}