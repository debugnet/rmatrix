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
unsigned int lines=1.5*maxx;
short int matrix[lines][5];
unsigned char randchr(){
srand(rand());
return (unsigned char)rand()*95/256+32;
}
for(x=1;x<=lines;++x){
srand(rand());
matrix[x][1] = -(unsigned short int)rand()*maxy/65536;
srand(rand());
matrix[x][2] = -(unsigned short int)rand()*maxy/65536;
if(matrix[x][2]>matrix[x][1]){matrix[x][2]=matrix[x][2]-(unsigned short int)rand()*maxy/65536;}
srand(rand());
matrix[x][3] = (unsigned short int)rand()*maxx/65536;
srand(rand());
matrix[x][5] = rand();
}
for(;;){
getmaxyx(stdscr, maxy, maxx);
attr=getch();
if(attr=='q'){endwin();exit(0);}
if(attr=='Q'){endwin();exit(0);}
for(x=1;x<=lines;++x){
attron(COLOR_PAIR(1));
if(matrix[x][1]-1>=0){
mvprintw(matrix[x][1]-1,matrix[x][3],"%c",matrix[x][4]);
}
srand(rand());
if(matrix[x][5]>(short int)rand()){
matrix[x][1] = matrix[x][1]+1;
matrix[x][4] = randchr();
}
attron(COLOR_PAIR(2));
if(matrix[x][1]>=0){
mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
}
srand(rand());
if(matrix[x][5]>(short int)rand()){
matrix[x][2] = matrix[x][2]+1;
if(matrix[x][2]>matrix[x][1]){matrix[x][2]=matrix[x][2]-(unsigned short int)rand()*maxy/65536;}
if(matrix[x][2]>maxy){
matrix[x][1]=0;
srand(rand());
matrix[x][2]=-(unsigned short int)rand()*maxy/65536;
srand(rand());
matrix[x][3]=(unsigned short int)rand()*maxx/65536;
srand(rand());
matrix[x][5]=rand();
}
}
if(matrix[x][2]>=0){
mvprintw(matrix[x][2],matrix[x][3]," ");
}
refresh();
}
}
}
