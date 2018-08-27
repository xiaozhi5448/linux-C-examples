#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
void ouch(int sig){
    printf("Oh, I got sig %d\n", sig);
    (void)signal(SIGINT, SIG_DFL);
}
int main(){
    struct sigaction act;
    act.sa_handler = ouch;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, 0);
    while(1){
        printf("Hello world!\n");
        sleep(1);
    }
    return 0;
}
