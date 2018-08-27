#include<unistd.h>
#include<stdio.h>
extern char **environ;
int main(int argc, char* argv[]){
    puts("输出执行参数:\n");
    for(int i = 0; i < argc; i++){
        printf("参数%d:%s\n", i, argv[i]);
    }
    puts("输出环境变量:\n");
    for(int i = 0;environ[i] != NULL; i++){
        printf("%s\n", environ[i]);
    }
    return 0;
}