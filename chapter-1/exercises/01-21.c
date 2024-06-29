#include <stdio.h>

#define TAB_STOP 8
#define IN 1
#define OUT 0

int main() {
  int i = 0, c;

  char state = OUT;
  // useful to handle the case where blanks end before a tab stop
  int i_was = i;
  // useful for finding out when to put a tab
  int next_stop = 0;
  while ((c = getchar()) != EOF) {
    if (state == OUT) {
      if (c == '\n') {
        putchar(c);
        i = 0;
      } else if (c == ' ') {
        i_was = i;
        state = IN;
        next_stop = i + TAB_STOP - (i % TAB_STOP);
        ++i;
      } else {
        putchar(c);
        ++i;
      }
    } else {
      if (i == next_stop) {
        putchar('\t');
        i_was = i;
        next_stop = i + TAB_STOP - (i % TAB_STOP);
      }

      if (c != ' ') {
        while (i_was != i) {
          putchar(' ');
          ++i_was;
        }
        putchar(c);
        state = OUT;
      } else {
        ++i;
      }
    }
  }

  if (state == IN) {
    while (i_was != i) {
      putchar(' ');
      ++i_was;
    }
  }

  return 0;
}
