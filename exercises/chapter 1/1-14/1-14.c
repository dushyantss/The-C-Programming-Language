/* Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

/* We will show the frequency for the alpha-numeric characters only for now. The
 * default terminal size is 80, and this count is close enought to that.For the
 * vertical graph, we show the count reliably only upto 9999, after that the
 * counter resets. Hopefully the graph would look bad anyways if it is this big,
 * due to small terminal size.
 */

#include <stdio.h>

#define IN 1		   /* inside a word */
#define OUT 0		   /* outside a word */
#define DIGITS_INDEX 0     /* The starting index for digits */
#define UPPERCASE_INDEX 10 /* The starting index for uppercase characters */
#define LOWERCASE_INDEX 36 /* The starting index for lowercase characters */
#define TOTAL 62	   /* The total number of characters we are tracking */

void count_chars(int count[], int max);
void draw_vertical(int count[], int max);

int main()
{
	int i;
	int count[TOTAL];

	for (i = 0; i < TOTAL; i++)
		count[i] = 0;

	count_chars(count, TOTAL);

	printf("\n\n\n");

	draw_vertical(count, TOTAL);

	return 0;
}

void count_chars(int count[], int max)
{
	int c, i;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			count[c - '0' + DIGITS_INDEX] += 1;
		else if (c >= 'A' && c <= 'Z')
			count[c - 'A' + UPPERCASE_INDEX] += 1;
		else if (c >= 'a' && c <= 'z')
			count[c - 'a' + LOWERCASE_INDEX] += 1;
	}

	return;
}

void draw_vertical(int count[], int max)
{
	int i, j, max_i, tallest;
	max_i = max - 1;
	tallest = 0;

	for (i = 0; i < max; i++)
		if (count[i] > tallest)
			tallest = count[i];

	for (i = tallest; i > 0; i--) {
		printf("%4d |", i);
		for (j = 0; j < max; j++) {
			if (count[j] >= i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	printf("      --------------------------------------------------------------\n");

	printf("      0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\n");

	return;
}
