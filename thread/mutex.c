#include<stdio.h>

#include<stdlib.h>

#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
pthread_mutex_t mutex;
int exit_time = 1;
char work_area[1024];
void* thread_func(void* arg){
    printf("子线程正在执行，对互斥量加锁\n");
    pthread_mutex_lock(&mutex);
    while(strncmp(work_area, "end", 3) != 0){
        printf("len:%d\n", strlen(work_area) - 1);
        work_area[0] = '\0';
        printf("解锁互斥量\n");
        pthread_mutex_unlock(&mutex);
        puts("睡眠1秒！\n");
        sleep(1);
        printf("加锁，判断信息是否为空\n");
        pthread_mutex_lock(&mutex);
        while(work_area[0] == '\0'){
            printf("加锁成功！，轮询直到有信息传送！\n");
            pthread_mutex_unlock(&mutex);
            sleep(1);
            pthread_mutex_lock(&mutex);
        }
    }
    exit_time = 0;
    work_area[0] = '\0';
    pthread_mutex_unlock(&mutex);
    pthread_exit(EXIT_SUCCESS);
}

int main(){
    pthread_t thread;
    int res;
    void * thread_res;
    pthread_mutex_init(&mutex, NULL);
    if((res = pthread_create(&thread, NULL, thread_func, NULL)) != 0){
        perror("创建线程失败！");
        exit(EXIT_FAILURE);
    }
    
    while(exit_time){
        pthread_mutex_lock(&mutex);
        printf("type your string:\n");
        fgets(work_area, 1024, stdin);
        pthread_mutex_unlock(&mutex);
        while(1){
            pthread_mutex_lock(&mutex);
            if(work_area[0] != '\0'){
                pthread_mutex_unlock(&mutex);
                sleep(1);
                pthread_mutex_lock(&mutex);
            }else{
                pthread_mutex_unlock(&mutex);
                break;
            }
        }
        
    }
    
    printf("wait for the thread exit!\n");
    if((res = pthread_join(thread, thread_res)) != 0){
        perror("等待线程结束出错！");
        exit(EXIT_FAILURE);
    }
    printf("thread exited!");
    pthread_mutex_destroy(&mutex);
    exit(EXIT_FAILURE);
}