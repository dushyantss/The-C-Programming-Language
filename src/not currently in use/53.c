#include <stdio.h>

void strcat(char *s, char *t){
	while(*s)
		s++;
	while(*s++ = *t++)
		;
}

int main(void){
	char s[50] = "Hello World";
	char t[] = " this has been a good day";
	printf("%s\n%s\n", s, t);
	strcat(s, t);
	printf("%s\n", s);
	return 0;
}

