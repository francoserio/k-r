#include <limits.h>
#include <stdio.h>
#include <float.h>

int main() {

	printf("%s %d\n", "unsigned char max value: ", UCHAR_MAX);
	printf("%s %d\n", "unsigned char min value: ", CHAR_MIN);
	printf("%s %d\n", "signed char min value: ", SCHAR_MIN);
	printf("%s %d\n", "signed char max value: ", SCHAR_MAX);
	printf("%s %d\n", "int max value: ", INT_MAX);
	printf("%s %d\n", "int min value: ", INT_MIN);
	printf("%s %ld\n", "long max value: ", LONG_MAX);
	printf("%s %ld\n", "long min value: ", LONG_MIN);
	printf("%s %d\n", "short max value: ", SHRT_MAX);
	printf("%s %d\n", "short min value: ", SHRT_MIN);
	printf("%s %lf\n", "float max value: ", FLT_MAX);
	printf("%s %lf\n", "float min value: ", FLT_MIN);
	printf("%s %lu\n", "unsigned long max value: ", ULONG_MAX);
	printf("%s %d\n", "unsigned int max value: ", UINT_MAX);
	printf("%s %d\n", "unsigned char max value: ", UCHAR_MAX);
	printf("%s %d\n", "unsigned short max value: ", USHRT_MAX);
	printf("%s %f\n", "double max value: ", DBL_MAX);
	printf("%s %f\n", "double min value", DBL_MIN);

	return 0;
}