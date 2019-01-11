/* Exercise 1-16. Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrary long input lines, and as much as
 * possible of the text.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

int main()
{
	int len;	       /* current line length */
	int max;	       /* maximum length seen so far */
	char line[MAXLINE];    /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	int c;		       /* The temp char to calculate max line */

	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0) {
		/* Calculate the actual longest line, the old code would not work on lines
     * longer than MAXLINE
     */
		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') { /* line bigger than MAXLINE */
			while ((c = getchar()) != EOF && c != '\n')
				len++;
			if (c == '\n')
				len++;
		}
		if (len > max) {
			max = len;
			my_copy(longest, line);
		}
	}
	if (max > 0) /* there was a line */
		printf("%s\n", longest);

	return 0;
}

/* my_getline:  read a line into s, return length  */
int my_getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* my_copy: copy 'from' into 'to'; assume to is big enough */
void my_copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
