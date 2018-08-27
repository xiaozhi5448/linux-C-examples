#include<db.h>
#include<stdio.h>

void my_error_handler(char* prefix, char* msg){
    printf("%s: %s\n", prefix, msg);
}

int main(){
    DB* dbp;
    int res;
    if((res = db_create(&dbp, NULL, 0)) != 0){
        fprintf(stderr, "%s: %s\n", "数据包初始化失败", db_strerror(res));
        return res;
    }
    dbp->set_errcall(dbp, my_error_handler);
    dbp->set_errpfx(dbp, "数据包");
    puts("初始化数据库成功！\n");
    res = dbp->open(dbp,
        NULL,
        "mysql.db",
        NULL,
        DB_BTREE,
        DB_CREATE,
        0);
    if(res != 0){
        dbp->err(dbp, res, "数据文件打开失败: %s", "mysql.db");
        return res;
    }
    puts("打开数据文件成功\n");
    
    if(dbp != NULL){
        puts("关闭数据库实例！");
        dbp->close(dbp, 0);
    }
    // puts("重命名文件\n");
    // if(dbp != NULL){
    //     dbp->rename(dbp, "mysql.db", NULL, "mysql2.db", 0);
    // }
    // puts("删除数据文件\n");
    // if(dbp != NULL){
    //     dbp->remove(dbp, "mysql2.db", NULL, 0);
    // }
    return 0;
}