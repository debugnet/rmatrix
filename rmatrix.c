#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main() {
int maxy, maxx;
int x;
char inp;
srand(time(NULL));
srand48(time(NULL));
initscr();
start_color();
use_default_colors();
init_pair(1,COLOR_GREEN,-1);
init_pair(2,COLOR_WHITE,-1);
color_set(1,NULL);
noecho();
nodelay(stdscr,true);
curs_set(0);
getmaxyx(stdscr, maxy, maxx);
unsigned int lines=(unsigned int)(drand48()*2*(maxx+maxy))+1;
unsigned int delay=((unsigned int)(drand48()*20000)-(lines%20000)*2)+1000;
signed long int matrix[lines][5];
unsigned char randchr(){
return rand()%95+32;
}
for(x=0;x<lines;x++){
matrix[x][1] = -((unsigned long int)rand()%maxy*2);
matrix[x][2] = -((unsigned long int)rand()%maxy*2);
if(matrix[x][2]>=matrix[x][1]) matrix[x][2]-=(unsigned int)(rand()%maxy);
matrix[x][3] = (unsigned long int)rand()%maxx;
matrix[x][5] = rand();
}
while(1){
getmaxyx(stdscr, maxy, maxx);
inp=getch();
if(inp=='q'||inp=='Q'){clear();refresh();endwin();exit(0);}
for(x=0;x<lines;x++){
attron(COLOR_PAIR(1));
if(matrix[x][1]>=0){
mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
}
if(matrix[x][5]>rand()){
matrix[x][1]++;
matrix[x][4]=randchr();
}
move((unsigned int)rand()%maxy,(unsigned int)rand()%maxx);
if((unsigned char)(A_CHARTEXT&inch())!=' '){
printw("%c",randchr());
}
attron(COLOR_PAIR(2));
if(matrix[x][1]>=0) mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
if(matrix[x][5]>rand()){
matrix[x][2] = matrix[x][2]+1;
if(matrix[x][2]>matrix[x][1]) matrix[x][2]-=(unsigned int)(rand()%maxy);
if(matrix[x][2]>maxy){
matrix[x][1]=0;
matrix[x][2]=-(unsigned int)rand()%maxy;
matrix[x][3]=(unsigned int)rand()%maxx;
matrix[x][5]=rand();
}
}
if(matrix[x][2]>=0) mvprintw(matrix[x][2],matrix[x][3]," ");
}
refresh();
usleep(delay);
}
}
