#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>
sqlite3* dbptr;
int open_dbfile(char *filename){
    int res = sqlite3_open_v2(filename, &dbptr, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    if(res != 0){
        printf("打开数据文件失败:%s\n", sqlite3_errmsg(dbptr));
        return res;
    }
    puts("数据库已打开");
    return res;
}
int close_dbfile(char* filename){
    int res = sqlite3_close(dbptr);
    if(res != 0){
        printf("关闭数据库文件失败:%s\n", sqlite3_errmsg(dbptr));
        return res;
    }
    puts("数据库已关闭");
    return res;
}
void execute_sqlcmd(char* sqlcmd, char* msg){
    int res = sqlite3_exec(dbptr, sqlcmd, NULL, NULL, &msg);
    if(res != SQLITE_OK){
        printf("执行失败：%d-%s\n", res, msg);
    }else{
        printf("执行成功!");
    }
}
int main(){
    char* filename = "file.sqlite";
    int res = open_dbfile(filename);
    char* buf = (char*)malloc(50);
    char* sqlcmd = "create table call_list(\
                        id INTEGER PRIMARY KEY,\
                        type NUMERIC,\
                        telnum NUMERIC,\
                        bttime TEXT,\
                        tcount NUMERIC,\
                        charge_rate NUMERIC,\
                        charge_sum NUMERIC)";
    execute_sqlcmd(sqlcmd, buf);
    res = close_dbfile(filename);
    
    return 0;
}