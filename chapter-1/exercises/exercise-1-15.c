/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

#include <stdio.h>

float celsius(float fahr);

int main()
{
	float fahr;
	float lower, upper, step;

	lower = 0;   /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20;   /* step size */

	printf("Fahrenheit\tCelsius\n");

	fahr = lower;
	while (fahr <= upper) {
		printf("%10.0f\t%7.1f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}

float celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
