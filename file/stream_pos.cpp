#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#define CTIME 3
typedef struct{
    int length;
    fpos_t fpos;
} pos_t;
int main(){
    pos_t pos[CTIME];
    FILE *fp;
    if(creat("temp",0664) == -1){
        perror("创建文件失败！");
        return 1;
    }
    fp = fopen("temp","rw+");
    for(int i = 0; i< CTIME; i++){
        fgetpos(fp, &pos[i].fpos);
        pos[i].length = fprintf(fp, "第%d次输出的数据！\n", i);
    }
    fflush(fp);
    printf("文件总长度:%d\n", ftell(fp));
    rewind(fp);
    char *buf;
    for(int i =0; i < CTIME ; i++){
        fsetpos(fp, &pos[i].fpos);
        buf = (char*)malloc(pos[i].length + 1);
        *(buf + pos[i].length +1) = '\0';
        fread(buf, pos[i].length, 1, fp);
        printf("%s",buf);
        free(buf);
    }
    fclose(fp);
    return 0;

}