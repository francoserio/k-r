#include <stdio.h>

float convertFahrToCel(float fahr) {
	float res = (5.0/9.0)*(fahr-32.0);

	return res;
}

int main() {
	float myInt;
	scanf("%f", &myInt);
	float cel = convertFahrToCel(myInt);

	printf("%f\n", cel);

	return 0;
}