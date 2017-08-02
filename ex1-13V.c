#include <stdio.h>

#define IN 1
#define OUT 0
#define ARRAYLENGTH 10

int main() {

	int wordLength[ARRAYLENGTH] = { 0 };
	int c;
	int state = OUT;
	int length = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			// printf("%d\n", length);
			if (length > ARRAYLENGTH - 1) {
				wordLength[ARRAYLENGTH-1] = wordLength[ARRAYLENGTH-1] + 1;
			} else {
				wordLength[length] = wordLength[length] + 1;
			}
			length = 0;
		} else if (state == OUT) {
			state = IN;
		} else if (state == IN) {
			++length;
		}
	}

	int max = 0;
	for (int i = 0; i < ARRAYLENGTH; ++i)
	{
		if (wordLength[i] > max) {
			max = wordLength[i];
		}
	}

	//now i have an array with all the length of the words.
	
	while (max > 0) {
		int j = 0;
		while (j < ARRAYLENGTH) {
			// int jAnterior = j;
			if (wordLength[j] == max) {
				putchar('*');
				wordLength[j] = wordLength[j] - 1;
				putchar(' ');
				putchar(' ');
			} else {
				printf("%s", "   ");
			}
			++j;
		}
		putchar('\n');
		--max;
	}
	putchar('\n');

	for (int i = 0; i < ARRAYLENGTH; ++i) {
		if (i + 1 == ARRAYLENGTH) {
			printf("%s\n", ">10");
		} else {
			printf("%d %s", i + 1, " ");
		}
	}

	return 0;
}