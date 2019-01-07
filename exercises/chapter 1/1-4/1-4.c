/* Exercise 1-4. Write a program to print the corresponding Celsius to
   Fahrenheit table. */
#include <stdio.h>
/* print Celsius-Fahrenheit table for celsius = 0, 10, ..., 100 */
int main()
{
  int fahr, celsius;
  int lower, upper, step;
  lower = 0;   /* lower limit of temperature scale */
  upper = 100; /* upper limit */
  step = 10;   /* step size */
  celsius = lower;

  printf("The Celsius-Fahrenheit table for common values\n");

  while (celsius <= upper)
  {
    fahr = (celsius * 9 / 5) + 32;
    printf("%d\t%d\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}