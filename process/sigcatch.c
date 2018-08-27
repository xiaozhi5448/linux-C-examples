#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void ouch(int sig){
    printf("Oh, I got signal %d\n", sig);
    (void) signal(SIGINT, SIG_DFL);
}
int main(){
    (void) signal(SIGINT, ouch);
    while(1){
        printf("hello world!\n");
        sleep(1);
    }
}
