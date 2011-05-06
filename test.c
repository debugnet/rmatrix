#include <stdio.h>
#include <stdlib.h>

int main() {
srand(time(NULL));
int x;
srand(rand());
x = rand();
srand(rand());
printf("%d\n",(int)(x>rand()));
}

