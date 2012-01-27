//make sure to compile with -lncurses option in gcc
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main() {
int maxy, maxx;
int x,delay;
char inp;
short colr;
attr_t attr;
srand(time(NULL));
initscr();
noecho();
nodelay(stdscr,true);
start_color();
getmaxyx(stdscr, maxy, maxx);
int lines=.9*maxx;
short int matrix[lines][4];
unsigned char randchr(){
return (unsigned char)rand()%95+32;
}
//init matrix data
for(x=1;x<=lines;++x){
matrix[x][1] = (unsigned short int)rand()%maxy;
matrix[x][2] = (unsigned short int)rand()%maxy;
if(matrix[x][2]>=matrix[x][1]){
matrix[x][2] = matrix[x][2] - maxy;
}
matrix[x][3] = (unsigned short int)rand()%maxx;
}
while(1){
inp=getch();
if(inp=='q'||inp=='Q'){endwin();exit(0);}
for(x=1;x<=lines;++x){
// calc layer
if(matrix[x][1]>0){
matrix[x][4] = randchr();
}
mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
mvprintw(matrix[x][2],matrix[x][3]," ");
matrix[x][1] = matrix[x][1]+1;
matrix[x][2] = matrix[x][2]+1;
if(matrix[x][2]>maxy){
matrix[x][1]=0;
matrix[x][2]=(unsigned short int)rand()%maxy-maxy;
matrix[x][3]=(unsigned short int)rand()%maxx;
}
}
refresh();
}
endwin();

return 0;
}
