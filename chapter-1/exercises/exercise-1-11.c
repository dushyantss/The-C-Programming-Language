/* How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */
/* Usually when testing for bugs, we try and look at one good case, one bad case beyond each edge and all the edge cases. e.g. if we are expecting input from 0-10, then we test one good case(maybe 5), one bad case on each side(maybe -32 and 32) and then the edge cases (-1, 0, 10, 11). These should uncover most of the cases and give us a decent amount of confidence in our code.
 * We should try with one normal line with one word at least.
 * One line with no word.
 * One line with no character even.
 * One input with no line even. */
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c = '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
