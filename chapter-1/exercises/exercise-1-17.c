/* Write a program to print all input lines that are longer than 80 characters. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define PRINTABLE_LINE_LENGTH 80

int my_getline(char line[], int maxline);

/* print the longest input line */
int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = my_getline(line, MAXLINE)) > 0)
		if (len > PRINTABLE_LINE_LENGTH) {
			printf("length of line is %d and the line is as follows\n%s\n", len, line);
		}
	return 0;
}

/* my_getline:  read a line into s, return length  */
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
	if (c != EOF && c != '\n') {
		for (; (c = getchar()) != EOF && c != '\n'; ++i)
			;
	}
	return i;
}
