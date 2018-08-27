#include<stdio.h>
#include<unistd.h>
char *menu[] = {
    "a - add item!",
    "d - delete item!",
    "q - quit!",
    NULL,
};
char getchoice(char* greet, char** menus){
    char **option = menus;
    char selected;
    int chosen;
    printf("Choice: %s\n", greet);
    do{
        chosen = 0;
        while(*option){
        printf("%s\n", *option);
        option++;
        }
        do{
            selected = getchar();
        }while(selected == '\n');
        option = menus;
        while(*option){
            if(selected == *option[0]){
                chosen = 1;
                break;
            }
            option++;
        }
        if(!chosen){
            printf("invalid choice, again\n");
        }
    }while(!chosen);
    return selected;
}
int main(){
    char choice = ' ';
    if(!isatty(fileno(stdout))){
        fprintf(stderr, "sorry, you are not terminal! terminating...\n");
        return 1;
    }else{
        do{
            choice = getchoice("Please select a choice!", menu);
            printf("you choose %c\n", choice);
        }while(choice != 'q');
    }
    return 0;
}
