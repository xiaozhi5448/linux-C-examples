#include<stdio.h>
#include<fcntl.h>
#include<sys/uio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
    pid_t chpid;
    int fd;
    char buf[50];
    int status;
    if((fd=open("temp", O_CREAT | O_RDWR | O_TRUNC, 0664)) == -1){
        perror("创建文件：");
        return 1;
    }
    if((chpid = fork() == 0)){
        puts("子进程正在运行\n");
        strcpy(buf, "子进程数据！");
        printf("子进程pid：%d\n", getpid());
        printf("父进程pid：%d\n", getppid());
        write(fd, buf, strlen(buf));
        close(fd);
        exit(0);
    }else{
        puts("父进程正在运行！\n");
        strcpy(buf, "父进程数据!");
        printf("子进程pid：%d\n", chpid);
        printf("父进程pid：%d\n", getpid());
        write(fd, buf, strlen(buf));
        close(fd);
    } 
    wait(&status);
    return 0;
}