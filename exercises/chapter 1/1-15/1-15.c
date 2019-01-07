/* Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>

int convert(int fahr);

int main()
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0;   /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20;   /* step size */
	fahr = lower;

	printf("The Fahrenheit-Celsius table for common values\n");

	while (fahr <= upper) {
		celsius = convert(fahr);
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}

int convert(int fahr)
{
	return 5 * (fahr - 32) / 9;
}