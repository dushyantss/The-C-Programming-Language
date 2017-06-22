#include <stdio.h>

#define IN 1
#define OUT 0
/* count line, word and characters */

int main(){
	int numLine = 0, numWord = 0, numChar = 0, c, state = OUT;
	while((c = getchar()) != EOF){
		++numChar;
		if(c == '\n'){
			++numLine;
		}
		if(c == '\n' || c == ' ' || c == '\t'){
			state = OUT;
		} else if(state == OUT){
			++numWord;
			state = IN;
		}
	}
	
	printf("%d number of lines\n%d number of words\n%d number of characters", numLine, numWord, numChar);
	return 0;
}