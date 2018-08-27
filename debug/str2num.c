#include<stdio.h>
#include<string.h>
int main(){
    char num[10];
    int sum = 0;
    while(1){
        scanf("%s", num);
        long sum = 0;
        if(strcmp(num, "q") == 0){
            break;
        }
        for( int i = 0; i< strlen(num); i++ ){
            sum = sum*10 + num[i] - '0';
        }
        printf("sum=%d\n", sum);
    }
    return 0;
}
