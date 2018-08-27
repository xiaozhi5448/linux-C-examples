#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<limits.h>
#include<fcntl.h>
#define BUF_SIZE 4096
#define FIFO_NAME "/tmp/my_fifo"
int main(){
    int res;
    int pipe_fd;
    int mode = O_RDONLY;
    if(access(FIFO_NAME, F_OK) == -1){
        perror("fifo file not exists! exiting...");
        exit(EXIT_FAILURE);
    }
    char recv[BUF_SIZE + 1];
    int bytes_recv;
    printf("process %d open fifo file with mode O_RDONLY!\n", getpid());
    pipe_fd = open(FIFO_NAME, mode);
    printf("open fifo file with result %d\n", pipe_fd);
    if(pipe_fd != -1){
        do{
            res = read(pipe_fd, recv, BUF_SIZE);
            bytes_recv += res;
        }while(res > 0);
        printf("%d bytes received!\n", bytes_recv);
        close(pipe_fd);
    }else{
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}