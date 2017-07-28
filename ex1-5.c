#include <stdio.h>

int main() {
	printf("%3s %9s\n", "farenheit", "celsius");
	for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
		printf("%3d %14.1f\n", fahr, (5.0/9.0)*(fahr-32));		
	}

	return 0;
}