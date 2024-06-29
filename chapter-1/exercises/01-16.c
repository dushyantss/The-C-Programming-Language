#include <stdio.h>

// Maximum input line size
#define MAXLINE 10

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len, max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  printf("\n%d\t%s\n", max, longest);

  return 0;
}

int mygetline(char s[], int lim) {
  int i = 0;
  int c;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
    s[i] = c;
    ++i;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  if (c != EOF && c != '\n') {
    while ((c = getchar()) != EOF && c != '\n') {
      ++i;
    }

    if (c == '\n')
      ++i;
  }

  return i;
}

void copy(char to[], char from[]) {
  for (size_t i = 0; (to[i] = from[i]) != '\0'; i++) {
    ;
  }
}
