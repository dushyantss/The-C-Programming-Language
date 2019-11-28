/* Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main()
{
	long nb, nt, nl;
	int c;
	nb = 0;
	nl = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}
	printf("Blanks: %ld, Tabs: %ld, Newlines: %ld\n", nb, nt, nl);
}
