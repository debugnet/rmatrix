//make sure to compile with -lncurses option in gcc
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main() {
int maxy, maxx;
srand(time(NULL));
initscr();
getmaxyx(stdscr, maxy, maxx);
short int matrix[maxy][4];
int x;
unsigned char randchr(){
return (unsigned char)rand()*96/256+31;
srand(rand());
}
for(x=0;x<=maxy;++x){
matrix[x][1] = (short int)-((unsigned short int)rand()*maxy/65536);
srand(rand());
//waddch(stdscr,(char)matrix[x][1]);
//refresh();
}
for(x=0;x<=maxx;++x){
matrix[x][2] = (unsigned short int)rand()*maxx/65536;
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
mvaddch(rand()*maxy/65536,rand()*maxx/65536,randchr());
refresh();
sleep(2);

endwin();

return 0;
}
