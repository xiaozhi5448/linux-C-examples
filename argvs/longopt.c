#include<stdio.h>
#include<unistd.h>
#include<getopt.h>
#define _GNU_SOURCE
extern char* optarg;
extern int optopt, optind, opterr;
int main(int argc, char* argv[]){
    int opt;
    struct option options[] = {
        {"initialize", 0, NULL, 'i'},
        {"restart", 0, NULL, 'r'},
        {"stop", 0, NULL, 's'},
        {"file", 1, NULL, 'f'}
    };
    while((opt = getopt_long(argc, argv, "irsf:", options, NULL)) != -1){
        switch(opt){
            case 'i': 
            case 'r': 
            case 's': 
                printf("option:%c\n", opt);
                break;
            case 'f': 
                printf("filename:%s\n", optarg);
                break;
            default:
                printf("unknown arguments!");
                break;
        }
    }
    for(;optind < argc; optind++){
        printf("other argument:%s\n", argv[optind]);
    }
    return 0;
}