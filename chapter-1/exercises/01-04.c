#include <stdio.h>

int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 100;
	step = 10;

	printf("Celsius\tFahrenheit\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = 32 + ((9.0 / 5.0) * celsius);
		printf("%7.0f\t%10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
