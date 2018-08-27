#include<stdio.h>
#include<unistd.h>
extern char *optarg;
extern int opterr, optind, optopt;
int main(int argc, char *argv[]){
    int opt;
    while((opt = getopt(argc, argv, "if:rs")) != -1){
        switch(opt){
            case 'i': 
            case 'r': 
            case 's': 
                printf("option:%c\n", opt);
                break;
            case 'f': 
                printf("filename:%s\n", optarg);
            default: 
                printf("unknown argument!\n");
                break;
        }
    }
    for(;optind < argc; optind++){
        printf("argument:%s\n", argv[optind]);
    }
    return 0;
}