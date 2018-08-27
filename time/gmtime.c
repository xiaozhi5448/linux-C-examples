#include<stdio.h>
#include<time.h>
int main(){
    time_t the_time;
    time(&the_time);
    struct tm* tm_ptr = gmtime(&the_time);
    printf("the row time is:%ld\n", the_time);
    printf("the gmtime gives:\n");
    printf("date: %02d/%02d/%02d\n", tm_ptr->tm_year, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    return 0;
}