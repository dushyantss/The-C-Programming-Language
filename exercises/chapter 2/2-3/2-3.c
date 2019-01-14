/* Write a function htoi(s), which converts a string of hexadecimal digits 
 * (including an optional 0x or 0X) into its equivalent integer value. The 
 * allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

int my_getline(char line[], const int maxline);
int htoi(const char s[]);

int main(void)
{
	int len;
	char line[MAXLINE];
	while ((len = my_getline(line, MAXLINE)) > 0)
		printf("%d\n", htoi(line));
	return 0;
}

int htoi(const char s[])
{
	int len, i, sum, neg;
	sum = 0;
	len = strlen(s);
	i = 0;

	/* handle the '-' and '+' signs at the beginning */
	if (len > 1 && s[i] == '-')
		neg = 1;
	else
		neg = 0;

	if (neg || (len > 1 && s[i] == '+'))
		i = 1;

	/* handle the "0X" and '0x' at the beginning */
	if (len > i + 2 && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
		i += 2;

	for (; i < len && ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F')); i++)
		if (s[i] >= '0' && s[i] <= '9')
			sum = (sum * 16) + (s[i] - '0');
		else if (s[i] >= 'a' && s[i] <= 'f')
			sum = (sum * 16) + (s[i] - 'a') + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			sum = (sum * 16) + (s[i] - 'A') + 10;

	return neg ? -sum : sum;
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
