/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case and digits, and be prepared to handle cases like a-b-c
 * and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
 */

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

void expand(const char s1[], char s2[]);
int expandable(const char s[], int i);

int main(void)
{
	int len, i;
	char *s1, s2[MAXLINE];
	unsigned long max = MAXLINE;
	while ((len = getline(&s1, &max, stdin)) > 0) {
		expand(s1, s2);
		printf("%s", s2);
	}
	return 0;
}

void expand(const char s1[], char s2[])
{
	int i, j, k;
	for (i = j = 0; i < MAXLINE - 1 && j < MAXLINE - 1 && s1[i] != '\0'; i++) {
		/* cases to be handled are a-z, a-b, a-a and c-a. */
		if (s1[i] == '-' && expandable(s1, i)) {
			if (s1[i - 1] <= s1[i + 1]) {
				for (k = s1[i - 1] + 1; k <= s1[i + 1]; k++)
					s2[j++] = k;
				i++;
			} else if (s1[i - 1] > s1[i + 1]) {
				for (k = s1[i - 1] - 1; k >= s1[i + 1]; k--)
					s2[j++] = k;
				i++;
			}
		} else {
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
}

int expandable(const char s[], int i)
{
	return ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1])));
}
