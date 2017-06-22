#include <stdio.h>

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(){
	unsigned x = getbits(13u, 3, 3);
	printf("%d\n", x);
	x = getbits(64u, 6, 1);
	printf("%d", x);
	return 0;
}