#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* fp_read = popen("ps -ax", "r");
    if(fp_read == NULL){
        perror("create pipe to ps failed");
        exit(EXIT_FAILURE);
    }
    char info[1024];
    int num_char = fread(info, sizeof(char), 1024, fp_read);
    while(num_char>0){
        info[num_char - 1] = '\0';
        printf("got info: - \n%s\n", info);
        num_char = fread(info, sizeof(char), 1024, fp_read);
    }
    pclose(fp_read);
    exit(EXIT_SUCCESS);
}