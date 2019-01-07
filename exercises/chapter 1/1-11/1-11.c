/* Exercise 1-11. How would you test the word count program? What kinds of input
 * are most likely to uncover bugs if there are any?
 */
/*
 * To test anything, we need three types of inputs - Valid, Boundary and
 * Invalid.
 * Valid is anything like "a is a good boy\n" (works).
 * Boundary is like "" or "\n" or " ". (works).
 * Invalid would be a stream without EOF or Unicode characters (works).
 */
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		} else if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);

	return 0;
}
