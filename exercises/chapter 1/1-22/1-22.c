/* Write a program to "fold" long input lines into two or more shorter lines 
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */

/* Picked 81 as MAXLINE because the standard terminal size is 80x24.
 * The way that terminals work is such that they take in 81 characters and if
 * the 81st character is a newline, they just go to the next line, else they
 * print that character on a newline.
 * This behavior means that we have had to be clever in the code as well.
 */

#include <stdio.h>

#define MAXLINE 81

int fill(int line[], int lim, int extra);

int main(void)
{
	int len;
	int i;
	int extra;
	int line[MAXLINE];

	extra = 0;

	while ((len = fill(line, MAXLINE, extra)) > 0) {
		extra = 0;
		if (len == MAXLINE && line[len - 1] != '\n') {
			extra = line[len - 1];
			if (line[len - 1] == ' ') { /* Have to remove whitespaces */
				for (i = len - 1; i >= 0 && line[i] == ' '; i--)
					;
				line[i + 1] = '\n';
			} else { /* Have to break a word */
				line[len - 1] = '\n';
			}
		}

		for (i = 0; i < len && line[i] != '\n'; i++)
			putchar(line[i]);
		if (line[i] == '\n')
			putchar('\n');
	}

	return 0;
}

int fill(int line[], int lim, int extra)
{
	int c;
	int len;
	len = 0;
	if (extra != 0) {
		len = 1;
		line[0] = extra;
	}
	for (; len < lim && (c = getchar()) != EOF && c != '\n'; len++)
		line[len] = c;

	if (c == '\n') {
		line[len] = c;
		len++;
	}

	return len;
}