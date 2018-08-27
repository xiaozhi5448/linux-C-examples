#include<time.h>
#include<stdio.h>
int main(){
    struct tm* tm_ptr;
    time_t the_time;
    time(&the_time);
    printf("asctime gives:%s\n", asctime(localtime(&the_time)));
    printf("ctime gives:%s\n", ctime(&the_time));
    return 0;
}