/* Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n positions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void printb(unsigned long x);
unsigned int rightrot(unsigned int x, int n);

int main(void)
{
	unsigned int x;
	int n;
	unsigned long max = MAXLINE;
	char *line = NULL;
	char *split;
	unsigned long len;
	while ((len = getline(&line, &max, stdin)) > 0) {
		split = strtok(line, " ");
		x = strtoul(split, NULL, 2);

		split = strtok(NULL, " ");
		n = atoi(split);

		x = rightrot(x, n);

		printb(x);
		printf("\n");
	}
	return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
	/* first we take out the rightmost n bits */
	unsigned int y = ~(~0 << n) & x;

	/* now we shift it to the start of the int */
	y <<= sizeof(unsigned int) * 8 - n;

	x >>= n;

	return y | x;
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
