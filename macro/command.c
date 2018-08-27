#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

#define MAX(a, b) (a >= b) ? a:b
#define X 100
#define Y 101
#if X>Y
    printf("X>Y\n");
#elif X < Y
    
#else
    printf("X=Y\n");
#endif

#ifdef TRUE
   
#endif
#ifndef TRUE
    printf("boolean var is undefined!\n");
#endif
int main()
{
    if(TRUE)
    {
        printf("true\n");
    }else
    {
        printf("false\n");
    }
    printf("max num:%d\n",MAX(5, 10));
    //#error test message
    printf("filename:%s,line:%d,time:%s\n",__FILE__, __LINE__, __TIME__);
}