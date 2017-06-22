#include <stdio.h>

void lower(char s[]){
	for(int i = 0; s[i] != '\0'; ++i){
		s[i] =(s[i] >= 'A' && s[i] <= 'Z') ? s[i] + ('a' - 'A') : s[i];
	}
}

int main(){
	char str[] = "Hello THIS IS SPARTA. So, please be mindfuL.";
	printf(str);
	lower(str);
	printf("\n%s", str);
	return 0;
}