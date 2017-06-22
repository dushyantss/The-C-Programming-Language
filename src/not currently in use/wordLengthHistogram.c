#include <stdio.h>

#define IN 1
#define OUT 0

/* histogram about word length from 1 to 9 and then 10 & above */

int main(){
	int inWord = OUT, charCount = 0;
	int c;
	int charLength[10];
	for(int i = 0; i < 10; i++){
		charLength[i] = 0;
	}
	while((c = getchar()) != EOF ){
		if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))){
			inWord = OUT;
		} else{
			inWord = IN;
		}
		if(inWord == IN){
			++charCount;
		}else{
			if(charCount > 0){
				if(charCount <= 10){
					++charLength[charCount - 1];
				}else{
					++charLength[9];
				}
			}
			charCount = 0;
		}
	}
	
	int maxHeight = charLength[0];
	for(int i = 1; i < 10;i++){
		if(charLength[i] > maxHeight){
			maxHeight = charLength[i];
		}
	}
	
	printf("\n");
	for(int i = maxHeight; i > 0; i--){
		printf("%d |", i);
		if((charLength[0] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[1] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[2] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[3] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[4] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[5] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[6] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[7] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[8] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		if((charLength[9] - i) >= 0)
			printf(" ||");
		else printf("   ");
		
		printf("\n");
	}
	printf("---------------------------------\n");
	printf("0   1  2  3  4  5  6  7  8  9  10\n");
	
	return 0;
}