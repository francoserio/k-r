#include <stdio.h>

int main() 
{
	float fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	/* lower limit of temperature table */
	/*
	upper limit */
	/* step size */
	celsius = lower;
	printf("%s\n", "celsius-farenheit conversion table");
	printf("%3s %6s\n", "celsius", "farenheit");
	// printf("%6s\n", "celsius");
	while (celsius <= upper) {
		fahr = ((9.0/5.0) * celsius) + 32;
		printf("%3.0f %11.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}