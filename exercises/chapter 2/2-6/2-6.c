/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin 
 * at position p set to the rightmost n bits of y, leaving the other bits 
 * unchanged.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

unsigned long setbits(unsigned long x, int p, int n, unsigned long y);
void printb(unsigned long x);

int main(void)
{
	unsigned long x, y;
	int p, n;
	unsigned long max = MAXLINE;
	char *line = NULL;
	char *split;
	int len;
	while ((len = getline(&line, &max, stdin)) > 0) {
		split = strtok(line, " ");
		x = strtoul(split, NULL, 2);

		split = strtok(NULL, " ");
		p = atoi(split);

		split = strtok(NULL, " ");
		n = atoi(split);

		split = strtok(NULL, " ");
		y = strtoul(split, NULL, 2);

		x = setbits(x, p, n, y);

		printb(x);
		printf("\n");
	}
	return 0;
}

unsigned long setbits(unsigned long x, const int p, const int n, const unsigned long y)
{
	/* we will work with an example along side it.
   * assume, x = 0001 1101, p = 3, n = 2, y = 0110 1001
   */

	/* get the rightmost n bits of y.
   * In to the example, we will get -
   * 0000 0001
   */
	unsigned long yn = ~(~0 << n) & y;

	/* move these bits to the appropriate position.
   * In the example we'll get -
   * 0000 0100
   */
	yn = yn << (p + 1 - n);

	/* clear the n bits starting from p position in x.
   * In the example we'll get -
   * 0001 0001
   */
	unsigned long xp = ~(~(~0 << n) << (p + 1 - n)) & x;

	/* merge the two.
   * In the example we'll get -
   * 0001 0101
   */
	return yn | xp;
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
