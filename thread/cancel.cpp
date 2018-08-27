#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *thread_func(void *arg){
    int res;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if(res != 0){
        perror("设置线程取消失败");
        exit(EXIT_FAILURE);
    }
    if((res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL)) != 0){
        perror("设置线程取消类型失败！");
        exit(EXIT_FAILURE);
    }
    printf("子线程正在运行！\n");
    for(int i = 0; i < 10; i++){
        sleep(1);
        printf("子线程正在运行！\n");
    }
    pthread_exit(EXIT_SUCCESS);
}
int main(){
    int res;
    pthread_t thread;
    if((res = pthread_create(&thread, NULL, thread_func, NULL)) != 0){
        perror("线程创建失败！");
        exit(EXIT_FAILURE);
    }
    sleep(3);
    printf("取消线程！\n");
    if((res = pthread_cancel(thread)) != 0){
        perror("取消线程失败！");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}