#include<stdio.h>
#include"hello.h"
#include<dlfcn.h>
#include<stdlib.h>
typedef int (*FUNC)(void);
int main(){
    FUNC hello_func = NULL;
    void *handle = NULL;
    handle = dlopen("/home/xiaozhi/code/C++/linux/libs/dynamic/libhello.so", RTLD_LAZY);
    if(handle == NULL){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    dlerror();
    hello_func = (FUNC)dlsym(handle, "hello");
    if(hello_func == NULL){
        fprintf(stderr, "%s\n", dlerror());
    }
    hello_func();
    dlclose(handle);
    return 0;
}
