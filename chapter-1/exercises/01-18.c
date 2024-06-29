#include <stdio.h>

// Maximum input line size
#define MAXLINE 1000

int mygetline(char line[], int maxline);
int remove_trailing_whitespace(char line[], int len);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (remove_trailing_whitespace(line, len) > 0) {
      printf("%s\n", line);
    }
  }

  return 0;
}

int mygetline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

int remove_trailing_whitespace(char line[], int len) {
  int i = len - 1;
  while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
    --i;
  }

  ++i;
  line[i] = '\0';

  return i;
}
