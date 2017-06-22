#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y){
	return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

int main(){
	printf("%u", setbits(43, 3, 2, 32));
	return 0;
}