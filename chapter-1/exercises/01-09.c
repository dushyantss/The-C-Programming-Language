#include <stdio.h>

int main()
{
	int c, prev;

	prev = EOF;
	while ((c = getchar()) != EOF) {
		if (c == ' ' && c == prev) {
			continue;
		}
		putchar(c);
		prev = c;
	}
}
