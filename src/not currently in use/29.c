#include <stdio.h>

int bitcount(unsigned x){
	int b;
	
	// this works because each call to x&=(x-1) removes one bit
	// this can be seen in both cases where x is even or odd
	for(b = 0; x != 0; x&=(x-1))
		++b;
	return b;
}

int main(){
	printf("%d\n", bitcount(43));
	return 0;
}