#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<error.h>
#define LENGTH 2000
void copy(char* oldfile, char* newfile);
int main(int argc, char* argv[])
{
    
    if(argc != 3){
        puts("invalid arguments!\n");
        return 1;
    }
    copy(argv[1], argv[2]);
    return 0;
}
void copy(char* oldfile, char* newfile)
{
    char buf[LENGTH];
    int f1,f2,i, j=0;
    mode_t f_mode = S_IRUSR | S_IWUSR | S_IRGRP;
    f1 = open(oldfile, O_RDONLY);
    if(f1!= -1){
        puts("file opened successfully!\n");
        i = read(f1, buf, LENGTH);
        if(i>0){
            printf("%s\n",buf);
        }
        f2 = open(newfile, O_WRONLY|O_CREAT, f_mode);
        if(f2 != -1){
            write(f2, buf, i);
        }else{
            puts("create file failed!\n");
        }
        puts("write completed!\n");
    }else{
        puts("read file failed!");
        perror("file:");
    }
    
}