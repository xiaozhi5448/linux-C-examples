#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main(){
    int fd[2];
    char buf[200];
    int chpid;
    int len;
    //使用pipe系统调用创建一个管道，fd[0]用于读取，fd[1]用于写入
    if(pipe(fd) == -1){
        perror("创建管道出错：");
        exit(1);
    }
    if((chpid = fork()) == 0){
        close(fd[1]);
        //从fd[0]中读取数据到buf缓冲区
        len = read(fd[0], buf, sizeof(buf));
        buf[len] = 0;
        printf("子进程从管道读取数据：%s\n", buf);
        exit(0);
    }else{
        close(fd[0]);
        //sprintf函数将格式化数据写入缓冲区中
        sprintf(buf, "父进程为子进程（pid=%d）创建的数据！\n", chpid);
        //使用write系统调用将buf中的数据写入fd[1]指向的管道中
        write(fd[1], buf, strlen(buf));
        exit(0);
    }
    return 0;
}