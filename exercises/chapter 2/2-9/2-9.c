/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of
 * bitcount.
 */

/* There are two cases with x -
 * - x is odd -> the rightmost 1 bit is the first one and that would get
 * deleted. e.g. 1011 & 1010 = 1010
 * - x is even -> the righmost 1 bit is replaced by 1s in all the lower spots
 * when 1 is subtracted. e.g. 1100 - 1 = 1011, => 1100 & 1011 = 1000
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int bitcount(unsigned x);

int main(void)
{
	int len, i;
	char *line;
	unsigned long max = MAXLINE;
	while ((len = getline(&line, &max, stdin)) > 0) {
		i = atoi(line);
		printf("%d\n", bitcount(i));
	}
	return 0;
}

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
	int b = 0;
	while (x) {
		x &= x - 1;
		b++;
	}
	return b;
}
