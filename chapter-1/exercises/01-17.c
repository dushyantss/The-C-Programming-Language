#include <stdio.h>

#define MINLINE 80

int main()
{

	int i, c = 0;
	char line[MINLINE + 1];
	while (c != EOF) {
		i = 0;
		c = 0;
		while ((c = getchar()) != EOF && c != '\n') {
			if (i < MINLINE) {
				line[i] = c;
			} else if (i == MINLINE) {
				line[i] = '\0';
				printf("%s", line);
				putchar(c);
			} else {
				putchar(c);
			}
			++i;
		}

		if (c == '\n') {
			if (i == MINLINE) {
				line[i] = '\0';
				printf("%s", line);
			}

			if (i >= MINLINE) {
				putchar(c);
			}
		}
	}

	return 0;
}
