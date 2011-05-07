//make sure to compile with -lncurses option in gcc
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main() {
int maxy, maxx;
int x;
char attr;
srand(time(NULL));
initscr();
start_color();
init_pair(1,COLOR_GREEN,COLOR_BLACK);
init_pair(2,COLOR_WHITE,COLOR_BLACK);
color_set(1,NULL);
noecho();
nodelay(stdscr,true);

getmaxyx(stdscr, maxy, maxx);
unsigned int lines=.9*maxx;
short int matrix[lines][5];
unsigned char randchr(){
srand(rand());
return (unsigned char)rand()*94/256+32;
}
//init matrix data
for(x=1;x<=lines;++x){
srand(rand());
matrix[x][1] = (unsigned short int)rand()*maxy/65536;
srand(rand());
matrix[x][2] = (unsigned short int)rand()*maxy/65536-maxy;
if(matrix[x][2]>matrix[x][1]){matrix[x][2]=matrix[x][1];}
srand(rand());
matrix[x][3] = (unsigned short int)rand()*maxx/65536;
srand(rand());
matrix[x][5] = rand();
}
for(;;){
getmaxyx(stdscr, maxy, maxx);
//lines=.9*maxx;
//short int matrix[lines][5];
attr=getch();
if(attr=='q'){endwin();exit(0);}
if(attr=='Q'){endwin();exit(0);}
for(x=1;x<=lines;++x){
// calc layer
attron(COLOR_PAIR(1));
mvprintw(matrix[x][1]-1,matrix[x][3],"%c",matrix[x][4]);
if(matrix[x][1]>0){
matrix[x][4] = randchr();
}
attron(COLOR_PAIR(2));
mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
mvprintw(matrix[x][2],matrix[x][3]," ");
//mvinstr((unsigned short int)rand()*maxy/65536,(unsigned short int)rand()*maxx/65536,attr);
// display layer
//mvwprintw(stdscr,0,0,"%d",matrix[x][1]);
//mvwprintw(stdscr,1,0,"%d",matrix[x][2]);
//mvprintw(matrix[x][2],matrix[x][3]," ");
//mvwprintw(stdscr,(unsigned short int)rand()*maxy/65536,(unsigned short int)rand()*maxx/65536,"%c",randchr());
refresh();
srand(rand());
matrix[x][1] = matrix[x][1]+(int)(matrix[x][5]>(short int)rand());
srand(rand());
matrix[x][2] = matrix[x][2]+(int)(matrix[x][5]>(short int)rand());
if(matrix[x][2]>matrix[x][1]){matrix[x][2]=matrix[x][1];}
if(matrix[x][2]>maxy){
matrix[x][1]=0;
srand(rand());
matrix[x][2]=(unsigned short int)rand()*maxy/65536-maxy;
srand(rand());
matrix[x][3]=(unsigned short int)rand()*maxx/65536;
srand(rand());
matrix[x][5]=rand();
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
