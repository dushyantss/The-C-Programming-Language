#include <stdio.h>

int any(char s1[], char s2[]){
	int result = -1;
	for(int i = 0; s1[i] != '\0' && result < 0; ++i){
		for(int k = 0; s2[k] != '\0' && result < 0; ++k){
			if(s1[i] == s2[k])
				result = i;
		}
	}
	return result;
}

int main(){
	char s1[] = "abcdefghi";
	char s2[] = "jklmdnopce";
	
	printf("%d", any(s1, s2));
	return 0;
}