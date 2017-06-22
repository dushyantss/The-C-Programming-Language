#include <stdio.h>

int strlen(char *s){
	int i = 0;
	while(s[i++] != '\0')
		;
	return --i;
}

void strncpy(char *s, char *t, int n){
	for(int i = 0; i < n && (s[i] = t[i]) != '\0'; ++i)
		;
}

void strncat(char *s, char *t, int n){
	int slen = strlen(s);
	for(int i = 0; i < n && (s[i + slen] = t[i]) != '\0'; ++i)
		;
}

int strncmp(char *s, char *t, int n){
	int i = 0;
	while(i < n && t[i] != '\0' && s[i] == t[i])
		++i;
	if(i >= n)
		return 0;
	else
		return s[i] - t[i];
}
