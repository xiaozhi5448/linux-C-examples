#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<curses.h>
#include<string.h>
#define LEN_USER 20
#define LEN_PASS 20
int main(){
    char user_name[LEN_USER];
    char password[LEN_PASS];
    char *realpass="mypasswd";

    initscr();
    attron(A_BOLD);
    move(5, 10);
    printw("Please Login");
    attroff(A_BOLD);
    refresh();

    move(7, 10);
    printw("User name:");
    getnstr(user_name, 20);

    move(9, 10);
    printw("Password:");
    refresh();

    noecho();
    cbreak();

    memset(password, '\0', LEN_PASS);
    int i = 0;
    while(i < LEN_PASS){
        password[i] = getch();
        move(9, 20 + i);
        addch('*');
        refresh();
        if(password[i] == '\n'){
            break;
        }
        if(strcmp(password, realpass) == 0){
            break;
        }
        i++;
    }
    move(11, 10);
    if(strcmp(password, realpass) == 0){
        printw("Login successfully!");
    }else{
        printw("Login failed!");
    }

    refresh();
    sleep(2);
    endwin();
    return 0;
}