/* Write a function reverse(s) that reverses the character string s. Use it to 
 * write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int my_getline(char line[], int maxline);
void my_reverse(char line[], int len);

int main()
{
	int len;	    /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (line[len - 1] == '\n') {
			my_reverse(line, len - 1);
		} else {
			my_reverse(line, len);
		}
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

/* my_reverse: reverse the given string */
void my_reverse(char s[], int len)
{
	int temp;
	int i, j;
	i = 0;
	j = len - 1;
	while (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
