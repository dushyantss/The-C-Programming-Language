/* Write the function any(s1,s2), which returns the first location in a string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2. (The standard library function strpbrk does the same job
 * but returns a pointer to the location.)
 */

#include <stdio.h>

#define MAXLINE 1000

int contains(const char s[], const char c);
int any(const char s1[], const char s2[]);

int main(void)
{
	int len;
	char *line1, *line2;
	unsigned long max;
	max = MAXLINE;
	line1 = line2 = NULL;
	while ((len = getline(&line1, &max, stdin)) > 0 && (len = getline(&line2, &max, stdin)) > 0)
		printf("%d\n", any(line1, line2));
	return 0;
}

int any(const char s1[], const char s2[])
{
	int i;
	for (i = 0; s1[i] != '\0'; i++)
		if (contains(s2, s1[i]))
			return i;
	return -1;
}

int contains(const char s[], const char c)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;
	return 0;
}
