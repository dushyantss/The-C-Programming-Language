/* Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */

#include <stdio.h>

/* Doing the solution this way as these are the only keywords in the book till now. Solution would be much cleaner with else or &&/|| or their combination. */
int main()
{
	int c, old;
	old = EOF;
	while ((c = getchar()) != EOF) {
		if (c != old) {
			putchar(c);
		}
		if (c == old) {
			if (c != ' ')
				putchar(c);
		}
		old = c;
	}
}
