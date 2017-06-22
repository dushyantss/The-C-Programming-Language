#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char line[], int maxline);
void reverse(char to[], char from[]);

/*print reverse input line */
int main(){
	char line[MAXLINE];		/*current input line */
	char rev[MAXLINE];	/*reverse line saved here */

	while(getline(line, MAXLINE) > 0){
		reverse(rev, line);
		printf("%s", rev);
	}
	return 0;
}

/*getline: read a line into s, return length */
int getline(char s[], int lim){
	int c, i;
	
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char to[], char from[]){
	int length = 0;
	while( from[length] != '\n' && from[length] != '\0')
		++length;
	
	int i = 0, j = length - 1;
	
	while(j >= 0){
		to[i] = from[j];
		++i;
		--j;
	}
	if(from[length] == '\n'){
		to[length] = '\n';
		to[++length] = '\0';
	}else
		to[length] = '\0';
}