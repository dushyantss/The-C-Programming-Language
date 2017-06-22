#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input int *pn */
double getfloat(double *pn){
	int c, sign, power = 1;
	
	while(isspace(c = getch()))		/* skip whitespace */
		;
	
	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c !=  '.'){
		ungetch(c);		/* it's not a number */
		return 0.0;
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
	
	if(c == '.'){
		c = getch();
		if(!isdigit(c)){
			ungetch(c);
			ungetch('.');
			return 0;
		}
	}
	
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	
	if(c == '.'){
		c = getch();
		for(power = 1; isdigit(c); c = getch()){
			*pn = 10 * *pn + (c - '0');
			power *= 10;
		}	
	}
	
	*pn *= ((double)sign/power);
	if(c != EOF)
		ungetch(c);
	return c;
}

int main(void){
	double x;
	while(getfloat(&x)){
		printf("%f\n", x);
	}
	return 0;
}