#include<stdio.h>
#define SIZE 65535
#define LENGTH 1024
int main(){
    FILE *fp,*fp_copy;
    char buf[SIZE];
    fp = fopen("test.cpp","r");
    if(fp != NULL){
        puts("文件打开成功！");
        if(fread(buf, LENGTH, SIZE/LENGTH, fp) > 0){
            puts("文件读取成功！");
        }else{
            puts("文件读取失败!");
        }
    }else{
        perror("open file:");
        return 1;
    }
    fp_copy = fopen("test.txt", "w");
    if(fp_copy != NULL){
        puts("正在写入文件！");
        if(fwrite(buf, LENGTH, SIZE/LENGTH, fp_copy) >0){
            puts("文件写入成功！");
        }else{
            puts("写入失败！");
        }
    }
    if(fclose(fp)!= -1 && fclose(fp_copy) != -1){
        puts("文件关闭成功！");
    }else{
        perror("close file:");
        return 1;
    }
    return 0;
}