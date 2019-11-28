/* Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_SIZE 10
#define MAX_HEIGHT 20

int main()
{
	int c, state, size;
	// We will hold word sizes from 1-10+
	int word_count[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		word_count[i] = 0;

	state = OUT;
	size = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (size > 0) {
				if (size >= MAX_SIZE) {
					word_count[MAX_SIZE - 1] += 1;
				} else {
					word_count[size - 1] += 1;
				}
			}
			size = 0;
			state = OUT;
		} else {
			size += 1;
			state = IN;
		}
	}

	// Horizontal histogram
	printf("\nHorizontal Histogram of lengths of words \n");
	for (int i = 0; i < MAX_SIZE - 1; ++i) {
		printf("%3d | ", i + 1);
		for (int j = 0; j < word_count[i]; j++)
			printf("*");
		printf("\n");
	}
	printf("%d+ | ", MAX_SIZE);
	for (int j = 0; j < word_count[MAX_SIZE - 1]; j++)
		printf("*");
	printf("\n");

	// Vertical histogram
	printf("\n\nVertical Histogram of lengths of words \n\n");

	// first we find the height of the histogram
	int max = 0;
	for (int i = 0; i < MAX_SIZE; ++i)
		if (word_count[i] > max)
			max = word_count[i];

	// We will only go upto a max height of MAX_HEIGHT
	// We manually print the max line due to inclusion of +
	if (max >= MAX_HEIGHT) {
		printf("%d+ | ", MAX_HEIGHT);
		for (int j = 0; j < MAX_SIZE; ++j)
			if (word_count[j] >= MAX_HEIGHT)
				printf("* ");
			else
				printf("  ");
		printf("\n");
		max = MAX_HEIGHT - 1;
	}

	for (int i = max; i > 0; --i) {
		printf("%3d | ", i);
		for (int j = 0; j < MAX_SIZE; ++j)
			if (word_count[j] >= i)
				printf("* ");
			else
				printf("  ");
		printf("\n");
	}

	// Add the divider
	printf("---------------------------\n");

	// Add the numbers
	printf("    | 1 2 3 4 5 6 7 8 9 10+\n");
}
