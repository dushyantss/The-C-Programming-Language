/* Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */

/* For the solution, we will print both horizontal and vertical bars in the same
 * solution. We will keep the graph simple where we will count words with length
 * 1..9 and 10+. If the word is of length 10 or more, we will count it in 10+.
 * Also, for the vertical graph, we show the count reliably only upto 9999,
 * after that, the counter resets. Hopefully the graph would look bad anyways if
 * it is this big, due to small terminal size.
 */

#include <stdio.h>

#define IN 1   /* inside a word */
#define OUT 0  /* outside a word */
#define MAX 10 /* The maximum word size */

void count_words(int nwords[], int max);
void draw_horizontal(int nwords[], int max);
void draw_vertical(int nwords[], int max);

int main()
{
	int i;
	int nwords[MAX];

	for (i = 0; i < MAX; i++)
		nwords[i] = 0;

	count_words(nwords, MAX);

	printf("\n\n\n");

	draw_horizontal(nwords, MAX);

	printf("\n\n\n");

	draw_vertical(nwords, MAX);

	return 0;
}

void count_words(int nwords[], int max)
{
	int c, i, size, state, max_i;
	state = OUT;
	size = 0;
	max_i = max - 1;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				if (size < max)
					nwords[size - 1]++;
				else
					nwords[max_i]++;

				size = 0;
			}
		} else {
			size++;
			if (state == OUT)
				state = IN;
		}
	}

	return;
}

void draw_horizontal(int nwords[], int max)
{
	int i, j, max_i;
	max_i = max - 1;

	for (i = 0; i < max_i; i++) {
		printf("%3d | ", i + 1);

		for (j = 0; j < nwords[i]; j++)
			printf("*");

		printf("\n");
	}

	/* We handle the last one separately as we need to print 10+ */
	printf("%2d+ | ", max);

	for (j = 0; j < nwords[max_i]; j++)
		printf("*");

	printf("\n");

	return;
}

void draw_vertical(int nwords[], int max)
{
	int i, j, max_i, tallest;
	max_i = max - 1;
	tallest = 0;

	for (i = 0; i < max; i++)
		if (nwords[i] > tallest)
			tallest = nwords[i];

	for (i = tallest; i > 0; i--) {
		printf("%4d |", i);
		for (j = 0; j < max; j++) {
			if (nwords[j] >= i)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("      ------------------------------\n");

	printf("      ");

	for (i = 0; i < max_i; i++)
		printf(" %d ", i + 1);

	/* We handle the last one separately as we need to print 10+ */
	printf("%2d+", max);

	printf("\n");

	return;
}
