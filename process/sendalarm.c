#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
static int alarm_handled = 0;
void ding(int sig){
    alarm_handled = 1;
}
int main(){
    printf("process %d starting...\n", getpid());
    (void) signal(SIGALRM, ding);
    switch(fork()){
        case -1:
            perror("create process failed!");
            break;
        case 0:
            sleep(2);
            kill(getppid(), SIGALRM);
            exit(0);
            break;
    }
    printf("waiting for SIGALRM...\n");
    pause();
    if(alarm_handled){
        printf("catched the alarm sig!\n");
    }
    return 0;
}
