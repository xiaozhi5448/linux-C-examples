#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
void scan_dir(char *dir, int depth);
int main(){
    puts("scan dir /boot\n");
    scan_dir("/boot",0);
    puts("scan completed!\n");
    return 0;
}
void scan_dir(char *dir, int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if(dir==NULL){
        puts("you must input a dirname!");
        return;
    }
    if((dp = opendir(dir)) == NULL){
        printf("couldn't open the folder:%s\n", dir);
        return;
    }else{
        chdir(dir);
        while((entry = readdir(dp)) != NULL){
            lstat(entry->d_name, &statbuf);
            if(S_IFDIR & statbuf.st_mode){

                if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0){
                    continue;
                }
                printf("%*s%s/\n",depth, " ",entry->d_name);
                scan_dir(entry->d_name,depth+4);
            }else{
                printf("%*s%s\n", depth," ", entry->d_name);
            }

        }
        chdir("..");
        closedir(dp);
    }
}