/* Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */

#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
	int len, i;
	char *s, t[MAXLINE];
	unsigned long max = MAXLINE;
	while ((len = getline(&s, &max, stdin)) > 0) {
		escape(s, t);
		printf("%s\n", t);
		unescape(s, t);
		printf("%s", t);
	}
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;
	for (i = j = 0; i < MAXLINE - 1 && j < MAXLINE - 1 && s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i, j;
	for (i = j = 0; i < MAXLINE - 1 && j < MAXLINE - 1 && s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\\':
			if (s[i + 1] == 'n') {
				t[j++] = '\n';
				i++;
			} else if (s[i + 1] == 't') {
				t[j++] = '\t';
				i++;
			} else {
				t[j++] = s[i];
			}
			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}
