#include<syslog.h>
#include<stdio.h>
int main(){
    FILE* f = fopen("no_exist", "r");
    if(!f){
        syslog(LOG_ALERT | LOG_USER, "oops - %m\n");
        puts("log successfully!\n");
    }
    return 0;
}