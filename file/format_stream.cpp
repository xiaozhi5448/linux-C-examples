#include<stdio.h>
#include<fcntl.h>
typedef struct{
    char name[20];
    char address[50];
    char stu_id[15];
} student;
int main(){
    student stu1;
    FILE *fp;
    if(creat("info.txt",0664) == -1){
        perror("创建文件失败！");
        return 1;
    }
    fp = fopen("info.txt","w");
    if(fp != NULL){
        fprintf(fp,"<name>:%s <address>:%s <stu_id>:%s","xiaoming", "Beijing", "1010101");
        puts("输出信息成功!");
    }
    fclose(fp);
    fp = fopen("info.txt","r");
    fscanf(fp,"<name>:%s <address>:%s <stu_id>:%s", stu1.name, stu1.address, stu1.stu_id);
    fclose(fp);
    printf("%s,%s,%s\n",stu1.name,stu1.address,stu1.stu_id);
    return 0;
}