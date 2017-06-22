#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE 32

// here val is the power of 2 we want e.g. val = 3, result = 8
int powOf2(int val){
	return ( 1 << val);
}

void convertToBits(int val){
	if(val > 0)
		printf("0 ");
	else{
		printf("1 ");
		val*= -1;
	}
	
	for(int i = INT_SIZE - 2; i >= 0 ; --i){
		if(val >= powOf2(i)){
			printf("1 ");
			val = val % powOf2(i);
		}else
			printf("0 ");
	}
}

int main(int argc,char *argv[]){
	int val;
	for(int i = 1; i < argc; ++i){
		val = atoi(argv[i]);
		printf("%d\n", val);
		convertToBits(val);
		printf("\n");
	}
	return 0;
}