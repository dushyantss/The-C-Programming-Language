#include <stdio.h>
#include <ctype.h>

/* this function assumes that for a list to be formed we use the notation b-e for bcde
	and not use e-b for the reverse list as the second case is just one extra condition
	which is unnecessary with decent typing */
void expand(char s1[], char s2[]){
	int i, j;
	for(i = 0, j = 0; s1[i] != '\0'; ++i, ++j){
		if(s1[i] != '-')
			s2[j] = s1[i];
		//this if will check
		else if((isdigit(s1[i+1]) && isdigit(s1[i-1])) || (islower(s1[i+1]) && islower(s1[i-1])) || (isupper(s1[i+1]) && isupper(s1[i-1]))){
			if(s1[i+1] > s1[i-1]){
				++i;
				--j;
				while(s2[j] < s1[i]){
					++j;
					s2[j] = s2[j-1] + 1;
				}
			}else{
				++i;
				--j;
				while(s2[j] > s1[i]){
					++j;
					s2[j] = s2[j-1] - 1;
				}
			}
		}else
			s2[j] = s1[i];
	}
}

int main(){
	char s1[] = "i am a-z sure that 0-9 are e-a -a-k-";
	char s2[300];
	expand(s1, s2);
	printf("%s\n%s\n", s1, s2);
	return 0;
}