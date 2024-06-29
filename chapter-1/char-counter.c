#include <stdio.h>

int main() {
  unsigned long long nc = 0;

  while (getchar() != EOF)
    nc++;

  printf("%llu\n", nc);
}
