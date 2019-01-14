/* Write a function invert(x,p,n) that returns x with the n bits that begin at 
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the 
 * others unchanged.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

unsigned long invert(unsigned long x, int p, int n);
void printb(unsigned long x);

int main(void)
{
	unsigned long x;
	int p, n;
	unsigned long max = MAXLINE;
	char *line = NULL;
	char *split;
	unsigned long len;
	while ((len = getline(&line, &max, stdin)) > 0) {
		split = strtok(line, " ");
		x = strtoul(split, NULL, 2);

		split = strtok(NULL, " ");
		p = atoi(split);

		split = strtok(NULL, " ");
		n = atoi(split);

		x = invert(x, p, n);

		printb(x);
		printf("\n");
	}
	return 0;
}

unsigned long invert(unsigned long x, int p, int n)
{
	unsigned long y = ~(~0 << n) << (p + 1 - n);
	return x ^ y;
}

void printb(unsigned long x)
{
	int i = 0, j = 0, len = 0;
	int temp;
	char s[sizeof(unsigned long) * 8 + 1];
	while (x > 0) {
		if (x & 1)
			s[i] = '1';
		else
			s[i] = '0';
		x >>= 1;
		i++;
	}
	len = i;
	s[i] = '\0';
	for (i--; i > j; i--, j++) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	printf("%s\n", s);
}
