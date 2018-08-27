#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
using namespace std;
int main(){
    int fp;   
    mode_t fp_mode;
    fp_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    fp = open("test.txt", O_RDWR | O_CREAT, fp_mode);
    if ( fp != -1 ){
        printf("file created successfully!\n");
    }else{
        printf("failed!");
    }

    struct stat *buf = (struct stat*)malloc(sizeof(struct stat));
    if ( buf != NULL ){
        printf("buffer created successfully!\n");
    }else{
        printf("buffer created failed!\n");
    }
    fstat(fp, buf);
    if(buf->st_mode & S_IRUSR){
        printf("owner has read access!\n");
    }
    if(buf->st_mode & S_IWGRP){
        printf("group has write access!\n");
    }else{
        puts("group has no write access!");
    }
    close(fp);
    chmod("test.txt", 0664);
    stat("test.txt", buf);
    if(buf->st_mode & S_IWGRP){
        puts("group has write access!");
    }
    free(buf);



    char *dir = (char*)malloc(50);
    if(dir != NULL){
        getcwd(dir, 50);
        printf("current dir:%s\n", dir);
    }
    if(mkdir("test", 775) != -1){
        puts("dir created successfully!");
        chdir("test");
        puts("change workspace to test");
    }else{
        puts("couldn't create test dir!");
    }
    free(dir);
    

    

    return 0;
}
