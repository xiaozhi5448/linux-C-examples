#include<stdlib.h>
#include<stdio.h>
void main()
{
    char *p=NULL;
    p = malloc(50);
    if(p != NULL)
    {
        printf("please input your string:");
        scanf("%s", p);
        puts(p);
        free(p);
    }
    p = NULL;
}