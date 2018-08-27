#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    if(argc == 1 || argc > 3){
        fprintf(stderr, "invalid argument!");
        exit(1);
    }
    char *var = argv[1];
    char *value = getenv(var);
    if(value){
        printf("The environment variable %s has value %s\n", var, value);
    }else{
        printf("The environment variable %s has no value!\n", var);
    }

    if(argc == 3){
        value = argv[2];
        char *string = (char*)malloc(strlen(var) + strlen(value) + 2);
        if(string != NULL){
            strcpy(string, var);
            strcat(string, "=");
            strcat(string, value);
        }
        printf("calling putenv with string %s\n", string);
        if(putenv(string) != 0){
            fprintf(stderr, "putenv failed!\n");
            free(string);
            exit(1);
        }
        value = getenv(var);
        if(value){
            printf("new value of %s is %s\n", var, value);
        }else{
            printf("calling get env failed!\n");
        }
    }
    return 0;
}