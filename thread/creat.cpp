#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
char message[50] = "THREAD_TEST";
void* thread_func(void *arg);
int main(){
    pthread_t t_thread;
    void *thread_result;
    int res;
    res = pthread_create(&t_thread, NULL, thread_func, (void*)message);
    if(res != 0){
        perror("线程创建失败！");
        exit(EXIT_FAILURE);
    }
    printf("wait for the thread!\n");
    pthread_join(t_thread, &thread_result);
    printf("线程已结束，返回值为%s\n", (char*)thread_result);
    printf("message的值为%s\n", message);
    free(thread_result);
    exit(EXIT_SUCCESS);
}

void* thread_func(void *arg){
    printf("线程正在运行，参数为%s\n", (char*)arg);
    sleep(3);
    strcpy(message, "线程修改");
    char* buf = (char*)malloc(strlen("线程执行完毕！"));
    strcpy(buf, "线程执行完毕！");
    pthread_exit(buf);
}
