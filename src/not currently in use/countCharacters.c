#include <stdio.h>

int main(){
	long count = 0;
	while(getchar() != EOF){
		++count;
	}
	printf("%ld\n", count);
	
	return 0;
}