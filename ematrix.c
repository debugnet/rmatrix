#ifdef __unix__
#define OS_Windows 0
#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows 1
#include <windows.h>
#endif

#include <sys/ioctl.h>
#include <stdio.h>
//#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* adjustment factors for other machines */
#define THICKNESS .1
#define MAXDELAY 20000
#define MINDELAY 400
#define PLOT .5

int main() {
void getmaxyx(int *maxx,int *maxy){
if(OS_Windows){
#ifdef TIOCGSIZE
 struct ttysize ts;
 ioctl(STDIN_FILENO,TIOCGSIZE,&ts);
 *maxy=ts.ts_cols;
 *maxx=ts.ts_lines;
#elif defined(TIOCGWINSZ)
 struct winsize ts;
 ioctl(STDIN_FILENO,TIOCGWINSZ,&ts);
 *maxy=ts.ws_col;
 *maxx=ts.ws_row;
#endif
}else if(!OS_Windows){
CONSOLE_SCREEN_BUFFER_INFO csbi;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
*maxy=csbi.srWindow.Right-csbi.srWindow.Left+1;
*maxx=csbi.srWindow.Bottom-csbi.srWindow.Top+1;
}
}

/*
void *exit_thread(){
//converts getchar() to unbuffered:
struct termios old, new;
tcgetattr(0,&old);
new=old;
new.c_lflag &= ~ICANON;
tcsetattr(0,TCSANOW,&new);
char inp;
inp=getchar();
if(inp=='q'||inp=='Q'){printf("\e[2J");exit(0);} // clear();refresh();endwin();exit(0);} // quit
}
pthread_create(malloc(sizeof(pthread_t)),NULL,exit_thread,NULL);
*/

/* variables */
int maxy, maxx;
int x;

/* init options */
srand(time(NULL));
srand48(time(NULL));
//initscr();
printf("\e[2J");
//start_color();
printf("\e[32m");
//use_default_colors();
//init_pair(1,COLOR_GREEN,-1);
//init_pair(2,COLOR_WHITE,-1);
//color_set(1,NULL);
//noecho();
printf("\e[?25l");
//nodelay(stdscr,true);
//curs_set(0);

/* declare matrix */
getmaxyx(&maxy, &maxx);
unsigned int lines=(unsigned int)(drand48()*THICKNESS*(maxx*maxy)+1);
unsigned int delay=(unsigned int)((unsigned int)(MAXDELAY*(lines/(THICKNESS*(maxx*maxy))))+MINDELAY);
signed long int matrix[lines][5];

/* functions */
unsigned char randchr(){
return rand()%95+32;
}
void reinit(){
matrix[x][1] = -((unsigned long int)rand()%maxy*2);
matrix[x][2] = -((unsigned long int)rand()%maxy*2);
if(matrix[x][2]>=matrix[x][1]) matrix[x][2]-=(unsigned int)(rand()%maxy);
matrix[x][3]=(unsigned int)rand()%maxx;
matrix[x][0]=rand();
}

/* init matrix */
for(x=0;x<lines;x++){
reinit();
}

/* loop */
while(1){
getmaxyx(&maxy,&maxx);
// try without this for now
for(x=0;x<lines;x++){
//attron(COLOR_PAIR(1));
if(matrix[x][1]>0 && matrix[x][1]<=maxy){
//mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
printf("\e[%d;%dH\e[32m%c",matrix[x][1],matrix[x][3],matrix[x][4]);
}
if(matrix[x][0]>rand()){
matrix[x][1]++;
matrix[x][4]=randchr();
}
/* random plot */
/*
if(rand()>(PLOT*RAND_MAX)){
//move((unsigned int)rand()%maxy,(unsigned int)rand()%maxx);
// broke until i can get char at position
unsigned int rany=(unsigned int)rand()%maxy;
unsigned int ranx=(unsigned int)rand()%maxx;
int test=0;
for(x=0;x<lines;x++){if(matrix[x][1]<rany && matrix[x][2]>rany && matrix[x][3]==ranx) test++;}
if(test>0){
printf("\e[%d;%dH%c",rany,ranx,randchr());
//if((unsigned char)(A_CHARTEXT&inch())!=' ') printw("%c",randchr());
}
}
*/
//attron(COLOR_PAIR(2));
if(matrix[x][1]>0 && matrix[x][1]<=maxy) printf("\e[%d;%dH\e[37m%c",matrix[x][1],matrix[x][3],matrix[x][4]); //mvprintw(matrix[x][1],matrix[x][3],"%c",matrix[x][4]);
if(matrix[x][0]>=rand()){
matrix[x][2]++;
if(matrix[x][2]>=matrix[x][1]) matrix[x][2]=matrix[x][1]-1;
if(matrix[x][2]>=maxy){printf("\e[%d;%dH ",matrix[x][2],matrix[x][3]);reinit();}
}
if(matrix[x][2]>0) printf("\e[%d;%dH ",matrix[x][2],matrix[x][3]); // mvprintw(matrix[x][2],matrix[x][3]," ");
}
//refresh();
usleep(delay);
}
}
