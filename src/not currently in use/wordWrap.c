#include <stdio.h>
#define MAXLENGTH 10

/* this class will do word wrap */

int wrap(char line[]);

int main(){
	int count = 0, c;
	char line[MAXLENGTH];
	
	while((c = getchar()) != EOF){
		line[count] = c;
		++count;
		if(count >= MAXLENGTH){
			count = wrap(line);
		}
	}
}

int wrap(char line[]){
	int count = MAXLENGTH - 1, newline = 0;
	while(line[count] != ' ' && line[count] != '\t'){
		--count;
		++newline;
	}
	if(count < 0){
		printf("%s\n", line);
		return 0;
	}else{
		line[count] = '\0';
		printf("%s\n",line);
		for(int i = 0; i < newline; ++i){
			line[i] = line[count + 1 + i];
		}
		return newline;
	}
}