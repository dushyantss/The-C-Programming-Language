#include <stdio.h>

unsigned rightrot(unsigned x, int n){
	unsigned leftmostBit = ~(~(unsigned)0 >> 1);
	
	for(int i = 0; i < n; ++i){
		if(x & 1)
			x = (x >> 1) | leftmostBit;
		else
			x = (x >> 1);
	}
	
	return x;
	
	// if we know the length of unsigned then we can do this in a few steps
	// the block to rotate => a = ((pow(2, n) - 1) & x);
	// shift the block => a = (a << length - n);
	// merge the two values => x = (a | x);
}

int main(){
	printf("%u\n", rightrot(43, 3));
	return 0;
}