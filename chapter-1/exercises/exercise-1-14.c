/* Write a program to print a histogram of the frequencies of different characters in its input. */

#include <stdio.h>

#define CHAR_COUNT 26
#define MAX_HEIGHT 20

int main()
{
	int c;
	// We will only hold count from a to z and will consider upper case and lower case as the same i.e. `a` and `A` are the same
	int char_count[CHAR_COUNT];
	for (int i = 0; i < CHAR_COUNT; i++)
		char_count[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			char_count[c - 'a'] += 1;
		} else if (c >= 'A' && c <= 'Z') {
			char_count[c - 'A'] += 1;
		}
	}

	// Horizontal histogram
	printf("\nHorizontal Histogram of frequencies of characters \n");
	for (int i = 0; i < CHAR_COUNT; ++i) {
		printf("%c | ", 'a' + i);
		for (int j = 0; j < char_count[i]; j++)
			printf("*");
		printf("\n");
	}

	// Vertical histogram
	printf("\n\nVertical Histogram of frequencies of characters \n\n");

	// first we find the height of the histogram
	int max = 0;
	for (int i = 0; i < CHAR_COUNT; ++i)
		if (char_count[i] > max)
			max = char_count[i];

	// We will only go upto a max height of 20
	// We manually print the max line due to inclusion of +
	if (max >= MAX_HEIGHT) {
		printf("20+ | ");
		for (int j = 0; j < CHAR_COUNT; ++j)
			if (char_count[j] >= MAX_HEIGHT)
				printf("* ");
			else
				printf("  ");
		printf("\n");
		max = MAX_HEIGHT - 1;
	}

	for (int i = max; i > 0; --i) {
		printf("%3d | ", i);
		for (int j = 0; j < CHAR_COUNT; ++j)
			if (char_count[j] >= i)
				printf("* ");
			else
				printf("  ");
		printf("\n");
	}

	// Add the divider
	printf("---------------------------------------------------------\n");

	// Add the numbers
	printf("    | a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
}
