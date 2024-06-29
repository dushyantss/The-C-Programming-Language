#include <stdio.h>

// Maximum input line size
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void reverse(char line[], int len);

int main()
{
	int len, max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = mygetline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s\n", line);
	}

	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	s[i] = '\0';

	return i;
}

void reverse(char line[], int len)
{
	int i = 0;
	int j = len - 1;
	char temp;

	while (i < j) {
		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
		++i;
		--j;
	}
}
