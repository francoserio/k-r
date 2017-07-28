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
	fahr = lower;
	printf("%s\n", "farenheit-celsius conversion table");
	printf("%3s %12s\n", "farenheit", "celsius");
	// printf("%6s\n", "celsius");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %11.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}