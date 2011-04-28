#include <stdio.h>
#include <stdlib.h>

int main() {
srand(time(NULL));
int x;
for(x=0;x<=100;++x){
printf("%c",(char)((rand()&127/(127/96))+31));
srand(rand());
}
printf("\n");
}

