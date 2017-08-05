#include <stdio.h>

#define TABSTOPS 4
#define MAXLINE 1000

int main() {
	char line[MAXLINE];

	int c;
	int j = 0;
	int i = 0;
	while ((c = getchar()) != EOF ) {
		if (c == '\t') {
			while (j < TABSTOPS) {
				line[i] = ' ';
				++j;
				++i;
			}
		} else {
			line[i] = c;
			++i;
		}
		if (j + 1 == TABSTOPS) {
			j = 0;
		} else {
			++j;
		}
	}

	printf("%s\n", line);

	return 0;
}