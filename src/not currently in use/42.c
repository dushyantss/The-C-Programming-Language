#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]){
	double val, power, postE;
	int i , sign, signPostE;
	
	for(i = 0; isspace(s[i]);++i) //skip whitespace
		;
	sign = (s[i] == '-')? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		++i;
	for(val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		++i;
	for(power = 1.0; isdigit(s[i]); ++i){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if(s[i] == 'e' || s[i] == 'E'){
		++i;
		
		signPostE = (s[i] == '-') ? -1 : 1;
		++i;
		for(postE = 0.0; isdigit(s[i]); ++i)
			postE = 10.0 * postE + (s[i] - '0');
		if(signPostE  < 0)
			for(; postE > 0.0; --postE)
				power *= 10.0;
		else
			for(; postE > 0.0; --postE)
				power /= 10.0;
	}
	return sign * val/power;
}

int main(){
	char s[] = "  123.45e-6  ";
	printf("%s %8.8f \n", s, atof(s));
	return 0;
}