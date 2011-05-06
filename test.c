#include <stdio.h>
#include <stdlib.h>

int main() {
srand(time(NULL));
unsigned short int matrix[100][1];
int x;
for(x=1;x<=100;++x){
srand(rand());
matrix[x][1] = (unsigned short int)rand()*100/65536;
}
for(x=1;x<=100;++x){
//printf("%c",(char)((rand()&127/(127/96))+31));
printf("%d\n",matrix[x][1]);
}
printf("\n");
}

