#include<unistd.h>
#include<stdio.h>
extern char **environ;
int main(int argc, char* argv[]){
    puts("first information\n");
    fflush(stdout);
    execve("beexec", argv, environ);
    puts("information two!");
    return 0;
}