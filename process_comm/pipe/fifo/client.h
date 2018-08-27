#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define SERVER_FIFO_NAME "/tmp/server_fifo"
#define CLIENT_FIFO_NAME "/tmp/cli_%d_fifo"

#define BUF_SIZE 50
struct data_to_pass_st{
    pid_t pid;
    char some_data[BUF_SIZE - 1];
};
