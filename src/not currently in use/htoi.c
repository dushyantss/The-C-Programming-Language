#include <stdio.h>
#define IN 1
#define OUT 0

int check(char s[], int i){
	int result = 0;
	int state = IN;
	while(state){
		if(s[i] <= '9' && s[i] >= '0'){
			result = result * 16 + s[i] - '0';
			++i;
		}else if(s[i] <= 'F' && s[i] >= 'A'){
			result = result * 16 + s[i] - 'A' + 10;
			++i;
		}else
			state = OUT;
	}
	
	return  result;
}

int htoi(char s[]){
	int result = 0;
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
		result = check(s, 2);
	}else
		result = check(s, 0);
	
	return result;
}

int main(){
	
	char convert1[] = "12341234 is the answer";
	char convert2[] = "no 42 is the answer";
	char convert3[] = "0xAF3 is the only answer";
	
	printf("%d\n",htoi(convert1));
	printf("%d\n",htoi(convert2));
	printf("%d\n",htoi(convert3));
	
	return 0;
}