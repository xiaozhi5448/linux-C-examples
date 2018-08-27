#include<time.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[]){
    int i;
    time_t the_time;
    for(i = 0;i<10; i++){
        the_time = time((time_t*)0);
        printf("time is:%ld\n", the_time);
        sleep(2);
    }
    return 0;
}