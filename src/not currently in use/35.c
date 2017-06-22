#include <stdio.h>

void reverse(char s[]){
	int i = 0, j, c;
	while(s[i] != '\0')
		++i;
	--i;
	for(j = 0; j < i; --i, ++j){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* this version of itob should work for base <= 36 */
void itob(int n, char s[], int b){
	int i, sign = 1;
	if(n < 0){
		sign = -1;
		n *= -1;
	}
	//we will go right to left and then reverse the string
	if(b > 10){
		for(i = 0; n > 0; ++i){
			s[i] = n%b + '0';
			if(s[i] > '9')
				s[i] = n%b  - 10 + 'A';
			n/=b;
		}
		if(b == 16){
			s[i++] = 'x';
			s[i++] = '0';
		}
	}else{
		for(i = 0; n > 0; ++i){
			s[i] = n%b + '0';
			n/=b;
		}
		if(b == 8){
			s[i++] = '0';
		}
	}
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main(){
	int a = 123456;
	char s[33];
	itob(a, s, 2);
	printf("%d base 2 : %s\n", a, s);
	itob(a, s, 8);
	printf("%d base 8 : %s\n", a, s);
	itob(a, s, 16);
	printf("%d base 16 : %s\n", a, s);
	itob(a, s, 5);
	printf("%d, base 5 : %s\n", a, s);
	
	a *= -1;
	itob(a, s, 2);
	printf("%d base 2 : %s\n", a, s);
	itob(a, s, 8);
	printf("%d base 8 : %s\n", a, s);
	itob(a, s, 16);
	printf("%d base 16 : %s\n", a, s);
	itob(a, s, 5);
	printf("%d, base 5 : %s\n", a, s);
	
	return 0;
}