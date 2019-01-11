/* Write a program entab that replaces strings of blanks by the minimum number 
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * entab. When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 */

/* To understand this question, we have to understand the basics of tab stops in
 * typography. Tab stops are particular stops on the display and tab keys take
 * us to those spots when pressed. Tab key does not equal a fix number of
 * whitespaces, instead their sole job is to take the cursor to that particular
 * spot on the screen. e.g. in this program, we will be using fixed tab stops
 * every 8 columns(Here columns and characters are interchangeable).
 * So, a tab stop every 8 columns means that if the cursor is anywhere between 
 * col1 (index starts from 1) to col8 and we press tab, we are taken to col9.
 * 
 * Another important thing is that tabs are reset on each newline.
 */

#include <stdio.h>

#define COLUMNS 8

int i, j;
int store[COLUMNS];

void entab(int c);

int main(void)
{
	int c;
	i = 0;
	while ((c = getchar()) != EOF)
		entab(c);

	return 0;
}

void entab(int c)
{
	if (c == '\n' || c == '\t') {
		putchar(c);
		i = 0;
	} else if (c != ' ') {
		putchar(c);
		i++;
		i %= COLUMNS;
	} else {
		store[0] = ' ';
		for (j = 1; j < COLUMNS - i && c == ' '; j++) {
			c = getchar();
			store[j] = c;
		}
		if (c == ' ' || c == '\t')
			putchar('\t');
		else
			for (i = 0; i < j; i++)
				putchar(store[i]);
		i = 0;
	}
}
