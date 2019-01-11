/* Write a program detab that replaces tabs in the input with the proper number 
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter?
 */

/* To understand this question, we have to understand the basics of tab stops in
 * typography. Tab stops are particular stops on the display and tab keys take
 * us to those spots when pressed. Tab key does not equal a fix number of
 * whitespaces, instead their sole job is to take the cursor to that particular
 * spot on the screen. e.g. in this program, we will be using fixed tab stops
 * every COLUMNS(8) columns(Here columns and characters are interchangeable).
 * So, a tab stop every 8 columns means that if the cursor is anywhere from col1 
 * (index starts from 1) to col8 and press tab, we are taken to col9.
 * 
 * Another important thing is that tabs are reset on each newline.
 */

#include <stdio.h>

#define COLUMNS 8

int i, j;

void detab(int c);

int main(void)
{
	int c;
	i = 0;
	while ((c = getchar()) != EOF)
		detab(c);

	return 0;
}

void detab(int c)
{
	if (c != '\t' && c != '\n') {
		putchar(c);
		i++;
		i %= COLUMNS;
	} else if (c == '\n') {
		putchar(c);
		i = 0;
	} else {
		for (j = 0; j < COLUMNS - i; j++)
			putchar(' ');
		i = 0;
	}
}
