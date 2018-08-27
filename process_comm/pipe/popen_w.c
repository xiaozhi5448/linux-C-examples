#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE* fp_write = popen("od -c", "w");
    char info[50];
    sprintf(info, "once upon a time, there was ...");
    if(fp_write != NULL){
        fwrite(info, sizeof(char), strlen(info), fp_write);
        pclose(fp_write);
    }
    return 0;
}
