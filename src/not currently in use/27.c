#include <stdio.h>

unsigned inverse(unsigned x, int p, int n){
	return  ((x & ~(~(~0 << n) << (p + 1 - n))) | (~x & (~(~0 << n) << (p + 1 - n))));
}

int main(){
	printf("%u", inverse(43, 3, 2));
	return 0;
}