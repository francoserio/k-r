#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

	int wordLength[25] ={ 0 };
	int c;
	int state = OUT;
	int length = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			// printf("%d\n", length);
			if (length > 24) {
				wordLength[25] = wordLength[25] + 1;
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

	//now i have an array with all the length of the words.
	
	for (int j = 0; j < 25; ++j) {
		if (j == 24) {
 			printf("%s\n", ">25 --");
		} else {
			printf("%d %s", j+1, "--");	
		}
		
		for (int i = 0; i < wordLength[j]; ++i) {
			putchar('*');
		}
		putchar('\n');
	}

	return 0;
}
