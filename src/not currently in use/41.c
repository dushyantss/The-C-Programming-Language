/* stdrrindex: return rightmost index of t in s, -1 if none */
#include <stdio.h>
#define MAXLINE 1000

int stdrrindex(char s[], char t[]){
	int i, j, k, l = -1;
	
	for(i = 0; s[i] != '\0'; ++i){
		for(j=i, k=0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
			;
		if(k > 0 && t[k] == '\0')
			l = i;
	}
	return l;
}

int getline(char line[], int max);

char pattern[] = "ould";

/* find all lines matching pattern */
int main(){
	char line[MAXLINE];
	int found = 0;
	
	while(getline(line, MAXLINE) > 0){
		if (stdrrindex(line, pattern) >= 0){
			printf("%s", line);
			++found;
		}
	}
	return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim){
	int c, i;
	
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
