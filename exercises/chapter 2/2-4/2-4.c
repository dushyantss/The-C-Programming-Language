/* Write an alternative version of squeeze(s1,s2) that deletes each character in
 * s1 that matches any character in the string s2. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int my_getline(char line[], const int maxline);
int contains(const char s[], const char c);
void squeeze(char s1[], const char s2[]);

int main(void)
{
	int len;
	char line1[MAXLINE];
	char line2[MAXLINE];
	while ((len = my_getline(line1, MAXLINE)) > 0 && (len = my_getline(line2, MAXLINE)) > 0) {
		squeeze(line1, line2);
		printf("%s\n", line1);
	}
	return 0;
}

void squeeze(char s1[], const char s2[])
{
	int i, j;
	for (i = j = 0; s1[i] != '\0'; i++)
		if (!contains(s2, s1[i]))
			s1[j++] = s1[i];
	s1[j] = '\0';
}

int contains(const char s[], const char c)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;
	return 0;
}

/* my_getline:  read a line into s, return length  */
int my_getline(char s[], const int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
