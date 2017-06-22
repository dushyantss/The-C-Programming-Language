#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input int *pn */
int getint(int *pn){
	int c, sign;
	
	while(isspace(c = getch()))		/* skip whitespace */
		;
	
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);		/* it's not a number */
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-'){
		c = getch();
		if(!isdigit(c)){
			ungetch(c);
			ungetch((sign == -1) ? '-' : '+');
			return 0;
		}
	}
	
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

int main(void){
	int x;
	while(getint(&x)){
		printf("%d\n", x);
	}
	return 0;
}