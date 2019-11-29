/* Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reverse(char line[], int len);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
	}
	return 0;
}

int my_getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], int len)
{
	int i, j, temp;
	i = 0;
	j = len - 1;
	if (s[j] == '\n')
		--j;

	for (; i < j; ++i, --j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}