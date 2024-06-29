#include <stdio.h>

#define ASCII_LIMIT 128

int main() {
  int c;
  int nchars[ASCII_LIMIT];

  for (int i = 0; i < ASCII_LIMIT; ++i) {
    nchars[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++nchars[c];
  }

  // Horizontal histogram
  printf("\n\n");
  printf("Horizontal histogram of frequency of characters\n");
  for (int i = 0; i < ASCII_LIMIT; ++i) {
    printf("%c | ", i);
    for (int j = 0; j < nchars[i]; ++j) {
      printf("*");
    }
    printf("\n");
  }

  // Vertical histogram
  printf("\n\n");
  printf("Vertical histogram of frequency of characters\n");
  // first get max height
  int max = 0;
  for (int i = 0; i < ASCII_LIMIT; ++i) {
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
  printf("-------");
  for (int i = 0; i < ASCII_LIMIT; ++i) {
    printf("----");
  }
  printf("\n");
  printf("       ");
  for (int i = 0; i < ASCII_LIMIT; ++i) {
    printf("%c   ", i);
  }
  printf("\n");
}
