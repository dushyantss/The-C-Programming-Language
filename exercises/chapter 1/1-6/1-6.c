/* Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main()
{
	/* We can do this using the same program as the book, but all we
	 * have to test is that booleans are represented as 1 and 0 in C. So,
	 * I'll check that directly.
	 */
	printf("true is equal to %d\n", 1 == 1);  /* true is equal to 1 */
	printf("false is equal to %d\n", 1 == 2); /* false is equal to 0 */

	return 0;
}
