#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#define BUF_SIZE 4096
#define TEN_SEG (1024 * 10)

#define FIFO_NAME "/tmp/my_fifo"
int main(){
    int open_mode = O_WRONLY;
    int fifo_fd;
    int res;
    char buf[BUF_SIZE + 1];
    if(access(FIFO_NAME, F_OK) == -1){
        res = mkfifo(FIFO_NAME, 0777);
        if(res == -1){
            fprintf(stderr, "can't create fifo file %s\n", FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }
    printf("process %d open fifo O_WRONLY!\n", getpid());
    fifo_fd = open(FIFO_NAME, open_mode);
    printf("process %d result %d\n", getpid(), fifo_fd);
    int bytes_sent = 0;
    if(fifo_fd != -1){
        do{
            res = write(fifo_fd, buf, BUF_SIZE);
            if(res == -1){
                perror("error write data to fifo file");
                exit(EXIT_FAILURE);
            }
            bytes_sent += res;
        }while(bytes_sent < TEN_SEG);
        (void)close(fifo_fd);
    }else{
        exit(EXIT_FAILURE);
    }
    printf("process %d finished\n%d bytes sent!", getpid(), bytes_sent);
    exit(EXIT_SUCCESS);
}
