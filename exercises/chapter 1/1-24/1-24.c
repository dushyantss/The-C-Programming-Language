/* Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. (This program is hard if
 * you do it in full generality.)
 */

#include <stdio.h>

int par, brackets, braces, squote, dquote;

int main(void)
{
	int c;
	int last;

	par = brackets = braces = squote = dquote = 0;

	last = EOF;
	while ((c = getchar()) != EOF) {
		if (last == '/' && c == '*') {
			while ((c = getchar()) != EOF && !(last == '*' && c == '/'))
				last = c;

			if (c == EOF)
				return 1;
			last = EOF;
		} else {

			if (c == '{') {
				braces++;
			} else if (c == '}') {
				if (braces <= 0)
					return 1;
				braces--;
			} else if (c == '(') {
				par++;
			} else if (c == ')') {
				if (par <= 0)
					return 1;
				par--;
			} else if (c == '[') {
				brackets++;
			} else if (c == ']') {
				if (brackets <= 0)
					return 1;
				brackets--;
			} else if (c == '\'') {
				squote++;
				squote %= 2;
			} else if (c == '"') {
				dquote++;
				dquote %= 2;
			}

			if (last == '\\' && !(c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'r' || c == 't' || c == 'v' || c == '\\' || c == '\'' || c == '"' || c == '0'))
				return 1;

			last = c;
		}
	}

	return par + brackets + braces + squote + dquote;
}
