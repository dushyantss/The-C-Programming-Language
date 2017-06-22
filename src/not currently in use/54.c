#include <stdio.h>
#include <string.h>

int strend(char *s, char *t){
	char *s1 = s + strlen(s) - 1;
	int lent = strlen(t);
	char *t1 = t + lent - 1;
	int count = 0;
	while(*t1-- == *s1--)
		++count;
	return (count == lent) ? 1 : 0;
}

int main(){
	char s[] = "hello is it me you are looking for";
	char t[] = "you are looking for";
	if(strend(s, t))
		printf("It works!!!\n");
	return 0;
}