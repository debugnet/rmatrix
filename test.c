#include <stdio.h>
#include <stdlib.h>

int main() {
srand(time(NULL));
int x;
for(x=0;x<=255;++x){
//printf("%c",(char)((rand()&127/(127/96))+31));
printf("%d\n",(unsigned short int)rand()*100/65536);
srand(rand());
}
printf("\n");
}

