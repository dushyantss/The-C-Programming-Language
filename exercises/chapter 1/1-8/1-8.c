/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */
#include <stdio.h>

int main()
{
	int c, nl, b, t;
	nl = b = t = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		else if (c == ' ')
			++b;
		else if (c == '\t')
			++t;
	}

	printf("Input contains %d newlines, %d blanks and %d tabs\n", nl, b, t);

	return 0;
}
