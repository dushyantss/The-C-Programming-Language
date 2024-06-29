#include <stdio.h>

float celsius(float fahrenheit);

int main() {
  float fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("Fahrenheit\tCelsius\n");

  fahr = lower;
  while (fahr <= upper) {
    printf("%10.0f\t%7.1f\n", fahr, celsius(fahr));
    fahr = fahr + step;
  }
}

float celsius(float fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}
