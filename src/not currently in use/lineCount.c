#include <stdio.h>

int main(){
	long lineCount;
	int c = 0;
	for(lineCount = 0; (c = getchar()) != EOF;){
		if(c == '\n'){
			++lineCount;
		}
	}
	printf("%ld", lineCount);
	return 0;
}