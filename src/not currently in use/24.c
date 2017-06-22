#include <stdio.h>
#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]){
	int match = FALSE, j = 0, k = 0;
	for(int i = 0; s1[i] != '\0'; ++i){
		match = FALSE;
		for(k = 0; s2[k] != '\0' && s1[i] != s2[k]; ++k)
			;
		if(s1[i] == s2[k])
			match = TRUE;
		if(match == FALSE)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}

int main(){
	char str1[] = "abcdefg";
	char str2[] = "hijklade";
	squeeze(str1, str2);
	printf(str1);
	return 0;
}