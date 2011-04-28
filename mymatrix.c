//make sure to compile with -lncurses option in gcc
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main() {
int maxy, maxx;
srand(time(NULL));
initscr();
getmaxyx(stdscr, maxy, maxx);
int matrix[maxy][4];
int x;
char randchr(){
return (rand()&127/(127/96))+31;
srand(rand());
}
for(x=0;x<=maxy;++x){
matrix[x][1] = - (unsigned short int)rand()/(65536/maxy);
srand(rand());
//waddch(stdscr,(char)matrix[x][1]);
//refresh();
}
for(x=0;x<=maxx;++x){
matrix[x][2] = (unsigned short int)rand()/(65536/maxx);
srand(rand());
}
// mvwaddstr(stdscr, x, y, "text"); print single string at x, y
// mvaddch(y,x,c); move cursor to x, y
// waddch(stdscr, c); write char c at current cursor position and shift right one
// getyx(stdscr, y, x); set x and y with x and y cursor positions
// noecho(); stop print
// echo(); resume print
// mvwprintw(stdscr, y, x, "printf string", var); printf equiv for ncurses
// curs_set(0);
// sleep(3); can allow some time to enjoi view
mvaddch((rand()&65535)/(65535/maxy),(rand()&65535)/(65535/maxx),randchr());
refresh();
sleep(2);

endwin();

return 0;
}
