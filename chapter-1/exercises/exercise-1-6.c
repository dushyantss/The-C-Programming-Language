/* Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		printf("Before EOF c != getchar() is `%d`\n", c != EOF);
		putchar(c);
	}
	printf("After EOF c != getchar() is `%d`\n", c != EOF);
}
