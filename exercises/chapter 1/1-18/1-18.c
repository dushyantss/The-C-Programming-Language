/* Write a program to remove trailing blanks and tabs from each line of input, 
 * and to delete entirely blank lines.
 */

/* We will work under the assumption that we clear the trailing blanks and tabs
 * only for the line we get in my_getline and we assume that each line would end
 * withing 1000 characters.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int my_getline(char line[], int maxline);
void clear_trail(char line[], int len);

int main()
{
	int len;	       /* current line length */
	char line[MAXLINE];    /* current input line */
	while ((len = my_getline(line, MAXLINE)) > 0) {
		clear_trail(line, len);
    if (line[0] != '\0' && line[0] != '\n')
      printf("%s", line);
	}

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

/* clear_trail: remove trailing blanks and tabs from the given line */
void clear_trail(char line[], int len)
{
  if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') { /* line is longer than maxline */
    while (len >= 0 && (line[len] == ' ' || line[len] == '\t')) {
      line[len] = '\0';
      len--;
    }
  } else { /* line is within MAXLINE, we can just check past the \n */
    for (len = len - 2; len >= 0 && (line[len] == ' ' || line[len] == '\t'); len--) {
      line[len] = '\0';
    }
    line[len + 1] = '\n';
  }
}
