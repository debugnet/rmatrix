//make sure to compile with -lncurses option in gcc
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main() {
int maxy, maxx;
int x,delay;
short colr;
attr_t attr;
srand(time(NULL));
initscr();
start_color();
getmaxyx(stdscr, maxy, maxx);
int lines=.9*maxx;
short int matrix[lines][4];
unsigned char randchr(){
srand(rand());
return (unsigned char)rand()*96/256+31;
}
//init matrix data
for(x=1;x<=lines;++x){
srand(rand());
matrix[x][1] = (unsigned short int)rand()*maxy/65536;
srand(rand());
matrix[x][2] = (unsigned short int)rand()*maxy/65536;
if(matrix[x][2]>=matrix[x][1]){
matrix[x][2] = matrix[x][2] - maxy;
}
srand(rand());
matrix[x][3] = (unsigned short int)rand()*maxx/65536;
}
for(;;){
for(x=1;x<=lines;++x){
// calc layer
if(matrix[x][1]>0){
matrix[x][4] = randchr();
}
mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
mvprintw(matrix[x][2],matrix[x][3]," ");
// display layer
//mvwprintw(stdscr,0,0,"%d",matrix[x][1]);
//mvwprintw(stdscr,1,0,"%d",matrix[x][2]);
//mvprintw(matrix[x][2],matrix[x][3]," ");
//mvwprintw(stdscr,(unsigned short int)rand()*maxy/65536,(unsigned short int)rand()*maxx/65536,"%c",randchr());
refresh();
matrix[x][1] = matrix[x][1]+1;
matrix[x][2] = matrix[x][2]+1;
if(matrix[x][2]>maxy){
matrix[x][1]=0;
matrix[x][2]=(unsigned short int)rand()*maxy/65536-maxy;
matrix[x][3]=(unsigned short int)rand()*maxx/65536;
}
}
}
endwin();

return 0;
// mvwaddstr(stdscr, x, y, "text"); print single string at x, y
// mvaddch(y,x,c); move cursor to x, y
// waddch(stdscr, c); write char c at current cursor position and shift right one
// getyx(stdscr, y, x); set x and y with x and y cursor positions
// noecho(); stop print
// echo(); resume print
// mvwprintw(stdscr, y, x, "printf string", var); printf equiv for ncurses
// curs_set(0);
// sleep(3); can allow some time to enjoi view
}
