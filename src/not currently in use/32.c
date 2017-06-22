#include <stdio.h>

void escape(char to[], char from[]){
	for(int i = 0, j = 0; from[i] != '\0'; ++i){
		switch(from[i]){
			case '\n':
				to[j++] = '\\';
				to[j++] = 'n';
				break;
			case '\t':
				to[j++] = '\\';
				to[j++] = 't';
				break;
			default:
				to[j++] = from[i];
				break;
		}
	}
}

void reverseEscape(char to[], char from[]){
	for(int i = 0, j = 0; from[i] != '\0'; ++j){
		switch(from[i]){
			case '\\':
			++i;
			if(from[i] == 'n'){
				to[j] = '\n';
				++i;
			}else if(from [i] == 't'){
				to[j] = '\t';
				++i;
			}else
				to[j] = '\\';
			break;
			default:
			to[j] = from[i++];
		}
	}
}

int main(){
	char from[] = "hello	is	it	me you are 	looking\nfor	\n";
	char to[45];
	escape(to, from);
	printf("%s\n%s\n", from, to);
	reverseEscape(to, to);
	printf(to);
	return 0;
}