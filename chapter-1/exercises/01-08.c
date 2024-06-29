#include <stdio.h>

int main() {
  int c, nl, blanks, tabs;

  nl = blanks = tabs = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++nl;
    if (c == '\t')
      ++tabs;
    if (c == ' ')
      ++blanks;
  }

  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("Newlines: %d\n", nl);
}
