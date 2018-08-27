#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<string.h>
#include<pthread.h>
char work_area[1024];
sem_t semaphore;
void* thread_func(void* arg){
    sem_wait(&semaphore);
    while(strncmp(work_area, "end", 3) != 0){
        printf("len:%d\n", strlen(work_area) - 1);
        sem_wait(&semaphore);
    }
    pthread_exit(EXIT_SUCCESS);
}
int main(){
    int res;
    pthread_t thread;
    void* thread_res;
    res = sem_init(&semaphore, 0, 0);
    if(res != 0){
        perror("初始化信号量失败！");
        exit(EXIT_FAILURE);
    }
    if((res = pthread_create(&thread, NULL, thread_func, NULL)) != 0){
        perror("线程创建失败");
        exit(EXIT_FAILURE);
    }
    printf("please input a string:\n");
    while(strncmp(work_area, "end", 3) != 0){
        fgets(work_area, 1024, stdin);
        sem_post(&semaphore);
    }
    printf("wait for the thread exit!\n");
    if((res = pthread_join(thread, &thread_res)) != 0){
        perror("等待线程结束出错！");
        exit(EXIT_FAILURE);
    }
    printf("线程已退出！\n");
    sem_destroy(&semaphore);
    exit(EXIT_SUCCESS);
}