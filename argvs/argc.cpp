#include<stdio.h>
int main(int argc, char* argv[]){
    printf("program name:%s\n", argv[0]);
    for(int i = 1; i < argc ; i++){
        if(argv[i][0] == '-'){
            printf("option:%s\n", argv[i] + 1);
        }else{
            printf("argument:%s\n", argv[i]);
        }

    }
    return 0;
}
