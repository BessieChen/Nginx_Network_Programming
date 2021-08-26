#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_sig2(int signo)
{
    printf("my_sig2\n");
}

void my_sig(int signo)
{
    printf("get sig_quit\n");
    if(signal(SIGQUIT, my_sig2) == SIG_ERR)
    {
        printf("err5\n");
        exit(1);
    }
}

int main(int argc, char *const *argv)
{
    sigset_t newmask, oldmask;
    if(signal(SIGQUIT, my_sig) == SIG_ERR)
    {
        printf("err1\n");
        exit(1);
    }
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
        printf("err2\n");
        exit(1);
    }
    if(sigismember(&newmask, SIGQUIT))
    {
        printf("quit is member\n");
    }
    else{
        printf("quit is not member\n");
    }
    printf("about to sleep\n");
    int remain = sleep(20);
    if(remain > 0)
    {
        printf("don't get enough sleep\n");
    }
    printf("wake up\n");
    
    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    {
        printf("err3\n");
        exit(1);
    }
    if(sigismember(&oldmask, SIGQUIT))
    {
        printf("quit is member\n");
    }
    else{
        printf("quit is not member\n");
        printf("about to sleep\n");
        int remain = sleep(20);
        if(remain > 0)
        {
            printf("don't get enough sleep\n");
        }
        printf("wake up\n");
    }
    return 0;




}