#include<stdio.h>
int main(){
    char tmpname[L_tmpnam];
    char* filename;
    FILE* tempfile;
    filename = tmpnam(tmpname);
    printf("the tmp file name is:%s\n", filename);
    tempfile = tmpfile();
    if(tempfile){
        puts("open stream to tmpfile successfully!");
    }else{
        puts("open file failed!");
    }
    return 0;
}