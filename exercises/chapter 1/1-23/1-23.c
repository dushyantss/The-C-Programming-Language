/* Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't
 * nest.
 */

#include <stdio.h>

int remove_comment(void);

int main(void)
{
	int c;
	int last;

	last = EOF;
	while ((c = getchar()) != EOF) {
		if (last == '/' && c == '*') {
			while ((c = getchar()) != EOF && !(last == '*' && c == '/'))
				last = c;
			last = EOF;
		} else {
			if (last != EOF)
				putchar(last);

			last = c;
		}
	}

	return 0;
}
