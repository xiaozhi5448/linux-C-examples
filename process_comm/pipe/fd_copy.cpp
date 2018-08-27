#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
    int fd;
    if((fd = open("output", O_RDWR | O_CREAT, 0664)) == -1){
        perror("create file failed!:");
        exit(1);
    }
    close(1);
    dup(fd);
    puts("this message will be send to file!\n");
    close(fd);
    return 0;
}