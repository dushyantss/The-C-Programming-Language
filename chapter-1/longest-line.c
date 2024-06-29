#include <stdio.h>

// Maximum input line size
#define MAXLINE 1000

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

  printf("%s\n", longest);

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

void copy(char to[], char from[]) {
  for (size_t i = 0; (to[i] = from[i]) != '\0'; i++) {
    ;
  }
}
