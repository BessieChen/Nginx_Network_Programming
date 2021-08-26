#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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