#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
测试:
创建守护进程:
0. fork子进程, 父进程退出; 接下来都是子进程要执行的:
1. setsid(), umask(0)
2. 用open() 创建/dev/null的句柄fd
3. 将fd复制到屏幕输出, 键盘输入
4. close(fd)

守护进程:
    只会受到进程{而非内核/系统}的信号
    所以我们可以把系统信号{sighup,sigint,sigwinch}占为己有, 作为自定义信号

回忆: 守护进程和后台进程的区别
    1. 有输出的话       守护: 不会往屏幕输出    后台: 会往屏幕输出
    2. 如果关闭Xshell   守护: 不退出           后台: 退出
*/

int ngx_daemon()
{
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("err3\n");
        return -1;
    }
    else if(pid > 0)
    {
        exit(0);
    }

    if(setsid() == -1)
    {
        printf("err4\n");
        return -1;
    }
    umask(0);
    
    int fd = open("/dev/null",  O_RDWR);
    if(fd == -1)
    {
        printf("err8\n");
        return -1;
    }
    if(dup2(fd, STDIN_FILENO) == -1)
    {
        printf("err5\n");
        return -1;
    }
    if(dup2(fd, STDOUT_FILENO) == -1)
    {
        printf("err6\n");
        return -1;
    }
    if(fd > STDERR_FILENO)
    {
        if(close(fd) == -1)
        {
            printf("err7\n");
            return -1;
        }
    }
    return 1;
}

int main(int argc, char *const *argv)
{
    if(ngx_daemon() == -1)
    {
        printf("err\n");
    }
    else
    {
        for(;;)
        {
            sleep(1);
            printf("err2\n");
        }
    }
    return 0;
}
