#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define TEXT_SIZE 2048
struct share_mem_st{
    int controller;
    char message[TEXT_SIZE];
};
