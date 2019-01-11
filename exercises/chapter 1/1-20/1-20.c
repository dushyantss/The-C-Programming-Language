/* Write a program detab that replaces tabs in the input with the proper number 
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define COLUMNS 2

int i;

void detab(int c);

int main(void)
{
	int c;
	while ((c = getchar()) != EOF)
		detab(c);

	return 0;
}

void detab(int c)
{
	if (c != '\t')
		putchar(c);
	else
		for (i = 0; i < COLUMNS; i++)
			putchar(' ');
}
