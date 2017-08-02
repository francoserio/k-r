#include <stdio.h>

#define IN 1
#define OUT 0
#define ARRAYLENGTH 256

int main() {

	int wordLength[ARRAYLENGTH] = { 0 };
	int c;
	int state = OUT;
	int length = 0;
	while ((c = getchar()) != EOF) {
		wordLength[c] = wordLength[c] + 1;
	}

	//now i have an array with all the length of the words.
	
	for (int j = 0; j < ARRAYLENGTH; ++j) {
		printf("%c %s", j, ": ");	
		
		for (int i = 0; i < wordLength[j]; ++i) {
			putchar('*');
		}
		putchar('\n');
	}

	return 0;
}