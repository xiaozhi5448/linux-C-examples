#include<syslog.h>
#include<stdio.h>
#include<unistd.h>
int main(){
    int logmask;
    openlog("test logmask", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_DEBUG, "test debug log, this message should exist!");
    syslog(LOG_INFO, "program pid is %d\n", getpid());
    logmask = setlogmask(LOG_UPTO(LOG_INFO));
    syslog(LOG_DEBUG, "this message should not exist!\n");
    return 0;
}