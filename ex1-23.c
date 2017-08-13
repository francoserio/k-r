
#include <stdio.h>

#define MAXLENGTH 5000

int getlines(void);
void replaceAndCopy(int le);

char line[MAXLENGTH];
char result[MAXLENGTH];

void removeComments(int len) {
	extern char line[];
	extern char result[];

	int j = 0;
	int i = 0;

	int esParteDeString = 0;

	while (i < len) {
		if (line[i] == '"' || line[i] == '\'') {
			if (esParteDeString == 0) {
				esParteDeString = 1;
			} else {
				esParteDeString = 0;
			}
		}
		if (line[i] == '/' && i < len - 1 && line[i+1] == '/' && esParteDeString == 0) {
			//es un comentario de una linea
			while (line[i] != '\n') {
				++i;
			}
		} else if (line[i] == '/' && i < len - 1 && line[i+1] == '*' && esParteDeString == 0) {
			//es un comentario de varias lineas.
			while ((line[i] != '*') || ((i < (len - 1)) && (line[i+1] != '/'))) {
				++i;
			}
			++i;
		} else {
			result[j] = line[i];
			++j;
		}
		++i;
	}
}

int getlines(void) {
	int c;
	int i;
	
	extern char line[];

	for (i = 0; i < MAXLENGTH-1 && (c = getchar()) != EOF; ++i) {
		line[i] = c;
	}
	line[i] = '\0';

	return i;
}

int main() {
	int len;

	extern char result[];

	if ((len = getlines()) > 0) {
		removeComments(len);
	}

	printf("\n%s\n%s\n", "Result:",result);

	return 0;

}
