#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
	int c, chars, state;
	int nchars[10];

	for (int i = 0; i < 10; ++i) {
		nchars[i] = 0;
	}

	state = OUT;
	chars = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				if (chars >= 10) {
					++nchars[9];
				} else {
					++nchars[chars - 1];
				}
			}
			state = OUT;
		} else if (state == OUT) {
			chars = 1;
			state = IN;
		} else {
			++chars;
		}
	}

	// Horizontal histogram
  printf("\n\n");
  printf("Horizontal histogram of lengths of words\n");
	for (int i = 0; i < 9; ++i) {
		printf("%3d | ", i + 1);
		for (int j = 0; j < nchars[i]; ++j) {
			printf("*");
		}
		printf("\n");
	}
	printf("10+ | ");
	for (int j = 0; j < nchars[9]; ++j) {
		printf("*");
	}
	printf("\n");

  // Vertical histogram
  printf("\n\n");
  printf("Vertical histogram of lengths of words\n");
  // first get max height
  int max = 0;
  for (int i = 0; i < 10; ++i) {
    if (nchars[i] > max) {
      max = nchars[i];
    }
  }
  // then start looping from max height and if any length touches that height
  // print it.
  for (int i = max; i > 0; --i) {
    // NOTE: This histogram gets distorted past 3 digit numbers, you can make
    // it more dynamic if you want, I got lazy.
    printf("%3d|", i);
    for (int j = 0; j < 10; ++j) {
      if (nchars[j] >= i) {
        printf("   *");
      } else {
        printf("    ");
      }
    }
    printf("\n");
  }
  printf("----------------------------------------------\n");
  printf("       1   2   3   4   5   6   7   8   9   10+\n");
}
