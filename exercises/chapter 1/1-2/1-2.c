/* Exercise 1-2. Experiment to find out what happens when prints's argument
 * string contains \c, where c is some character not listed above.
 */

/* This question is way too exploratory, so I have tested only a few characters.
 */

#include <stdio.h>

int main()
{
	/* \u and \x are special cases and the rest are tested here. */
	/* \c\d\g\h\i\j\k\l\m\o\p\q\s\w\y\z are not special characters */
	printf("\a\b\e\f\n\r\t\v");
}