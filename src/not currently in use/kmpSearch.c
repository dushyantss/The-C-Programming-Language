#include <stdio.h>
#include <string.h>

// this function will generate the lps array
void lpsArray(char pattern[], int lps[]){
	int m = strlen(pattern), i = 1, j = 0;
	lps[0] = 0;
	
	while(i < m){
		if(pattern[i] == pattern[j]){
			lps[i] = ++j;
			++i;
		}else if(j != 0)
			j = lps[j - 1];
		else
			lps[i++] = 0;
	}
}

// this function will put the indices of the matches found in the result array
int kmpSearch(char text[], char pattern[], int result[]){
	int i = 0, j = 0, m = strlen(pattern), n = strlen(text), k = 0;
	int lps[m];
	lpsArray(pattern, lps);
	
	while(i < n){
		if(pattern[j] == text[i]){
			++i;
			++j;
		}
		if(j == m){
			result[k++] = i - j;
			j = lps[j - 1];
		}else if( i < n && text[i] != pattern[j]){
			if(j == 0) ++i;
			else j = lps[j - 1];
		}
	}
	
	return k;
}

void copyString(char to[], char from[], int start, int end){
	int i = 0;
	while(start < end)
		to[i++] = from[start++]; 
}

int main(){
	char text[] = "aacaaaacaaaabaacaaacaaaaacaaaaaacaaaacaaaaacaacaaaacaaaacaa";
	char pattern[] = "aacaaaacaa";
	int result[20];
	int k = kmpSearch(text, pattern, result), i = 0, len = strlen(pattern);
	char temp[len + 1];
	temp[len] = '\0';
	while(i < k){
		copyString(temp, text, result[i], result[i] + len);
		printf("%s was found at %d index\n", temp, result[i++]);
	}
	return 0;
}