#include <stdio.h>

#define TAB_STOP 8

int main() {
  int i = 0, c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      putchar(c);
      i = 0;
    } else if (c == '\t') {
      int next_stop = i + TAB_STOP - (i % TAB_STOP);

      while (i != next_stop) {
        putchar(' ');
        ++i;
      }
    } else {
      putchar(c);
      ++i;
    }
  }
  return 0;
}
