/* Write a loop equivalent to the for loop above without using && or ||. */

#include <stdio.h>

int main(void)
{
	int i, c, lim;
	char s[100];
	lim = 10;
	/* for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	 * 	s[i] = c;
   */
	for (i = 0; i < lim - 1; ++i) {
		if ((c = getchar()) == '\n')
			break;
		else if (c == EOF)
			break;
		else
			s[i] = c;
	}

	return 0;
}