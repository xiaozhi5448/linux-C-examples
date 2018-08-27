#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define BUF_SIZE 1024
struct msg_st{
    long int msg_type;
    char data[BUF_SIZE];
};
