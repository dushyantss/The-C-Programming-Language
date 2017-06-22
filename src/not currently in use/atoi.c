#include <stdio.h>
#include <ctype.h>

/* atoi: convert s to integer; version 2 */
int atoi(char s[]){
	int i, n, sign;
	
	for(i = 0; isspace(s[i]); ++i)	/* skip whitespace */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-') /* skip sign */
		++i;
	for(n = 0; isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

int main(){
	char s1[] = "    -1234124 random";
	char s2[] = "12 rand 23 -32";
	printf("%d\n%d", atoi(s1), atoi(s2));
	return 0;
}