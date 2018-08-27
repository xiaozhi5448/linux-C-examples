#include<stdio.h>
#include<stdlib.h>
int main(){
    char info[50];
    FILE* fp = popen("uname -a", "r");
    if(fp == NULL){
        perror("create pipe to uname failed!");
        exit(0);
    }
    int num = fread(info, sizeof(char), 50, fp);
    printf("got information: - \n%s\n", info);
    return 0;
}
