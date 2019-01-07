/* Exercise 1-9. Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank.
 */
#include <stdio.h>

int main()
{
	int last, c;
	last = EOF;
	while ((c = getchar()) != EOF) {
		if (!(c == ' ' && last == c))
			putchar(c);
		last = c;
	}

	return 0;
}
