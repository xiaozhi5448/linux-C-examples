#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<curses.h>
int main(){
    char *witch_one = "First Witch  ";
    char *witch_two = "Second Witch ";
    char *scan_ptr;

    initscr();

    move(5, 15);
    attron(A_BOLD);
    printw("Macbeth");
    attroff(A_BOLD);
    refresh();
    sleep(1);

    move(8, 15);
    attron(A_STANDOUT);
    printw("Thunder and Lightning!");
    attroff(A_STANDOUT);
    refresh();
    sleep(1);

    move(10, 10);
    printw("%s", "When shall we three meet again?");
    move(11, 23);
    printw("%s", "string two");
    move(13, 10);
    printw("%s", "string three");
    move(14, 23);
    printw("%s", "string four");

    attron(A_DIM);
    scan_ptr = witch_one + strlen(witch_one) - 1;
    while(scan_ptr + 1 != witch_one){
        move(10, 10);
        insch(*scan_ptr--);
    }
    scan_ptr = witch_two + strlen(witch_two) - 1;
    while(scan_ptr + 1 != witch_two){
        move(13, 10);
        insch(*scan_ptr--);
    }
    attroff(A_DIM);
    refresh();
    sleep(1);

    move(LINES - 1, COLS - 1);
    refresh();
    sleep(1);

    endwin();
    exit(EXIT_SUCCESS);
}