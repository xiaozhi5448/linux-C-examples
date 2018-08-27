#include<stdio.h>
#include<stdlib.h>
#include<postgresql/libpq-fe.h>
static void exit_nicely(PGconn* conn){
    PQfinish(conn);
    exit(1);
}
void print_info(PGconn* conn){
    if(conn != NULL){
        printf("数据库名称:%s\n", PQdb(conn));
        printf("数据库用户:%s\n", PQuser(conn));
        printf("连接使用的口令:%s\n", PQpass(conn));
        printf("主机名称:%s\n", PQhost(conn));
        printf("主机端口:%s\n", PQport(conn));
        printf("协议：%d\n", PQprotocolVersion(conn));
        printf("服务器版本:%d\n", PQserverVersion(conn));
        printf("服务器进程id:%d\n", PQbackendPID(conn));
    }else{
        puts("invalid arguments!");
    }
}
void execute_command(PGconn* conn, const char* command){
    PGresult *res = PQexec(conn, command);
    if(PQresultStatus(res) != PGRES_COMMAND_OK){
        puts("命令执行出错!");
        exit_nicely(conn);
    }
    puts("命令执行成功!");
}
int main(){
    const char* conninfo = "host=localhost hostaddr=127.0.0.1 port=5432 user=dbuser dbname=exampledb password=wodemima";
    PGconn* conn;
    conn = PQconnectdb(conninfo);
    if(PQstatus(conn) != CONNECTION_OK){
        puts("连接数据库失败");
        exit_nicely(conn);
    }
    puts("数据库连接成功");
    print_info(conn);

    const char* sqlcmd = "create table call_list(\
                        id INTEGER[4] NOT NULL AUTO_INCREMENT PRIMARY KEY,\
                        type INTEGER[1],\
                        telnum INTEGER[4],\
                        bttime CHAR(14),\
                        tcount INTEGER[4],\
                        charge_rate FLOAT[4],\
                        charge_sum FLOAT[4])";
    execute_command(conn, sqlcmd);
    PQfinish(conn);
    puts("已断开连接");
    exit(0);
}