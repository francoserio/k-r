#include <stdio.h>

#define MAXLENGTH 5000
#define YES 1
#define NO 0

int getlines(void);
void replaceAndCopy(int le);

char line[MAXLENGTH];
char result[MAXLENGTH];

int checkSyntax(int len) {
	int i = 0;
	int res;

	int esParteDeString = 0;
	int esParteDeComentario = 0;

	int parenthesis = 0;
	int brackets = 0;
	int braces = 0;


	while (i < len) {

		if (line[i] == '"' || line[i] == '\'') {
			if (esParteDeString == 0) {
				esParteDeString = 1;
			} else {
				esParteDeString = 0;
			}
		}

		if ((line[i] == '/' && line[i+1] == '*') || (line[i] == '/' && line[i+1] == '/')) {
			if (esParteDeComentario == 0) {
				esParteDeComentario = 1;
			} else {
				esParteDeComentario = 0;
			}
		}

		if (line[i] == '(' && esParteDeString ==  0 && esParteDeComentario == 0) {
			++parenthesis; 
		} else if (line[i] == ')' && esParteDeString ==  0 && esParteDeComentario == 0) {
			--parenthesis;
		} else if (line[i] == ']' && esParteDeString ==  0 && esParteDeComentario == 0) {
			--brackets;
		} else if (line[i] == '[' && esParteDeString ==  0 && esParteDeComentario == 0) {
			++brackets;
		} else if (line[i] == '}' && esParteDeString ==  0 && esParteDeComentario == 0) {
			--braces;
		} else if (line[i] == '{' && esParteDeString ==  0 && esParteDeComentario == 0) {
			++braces;
		}
		++i;
	}

	if (parenthesis == 0 && brackets == 0 && braces == 0) {
		res = YES;
	} else {
		res = NO;
	}

	return res;
}

int getlines(void) {
	int c;
	int i;
	
	extern char line[];

	for (i = 0; i < MAXLENGTH-1 && (c = getchar()) != EOF; ++i) {
		line[i] = c;
	}
	line[i] = '\0';

	return i+1;
}

int main() {
	int len;
	char* res;

	extern char result[];

	if ((len = getlines()) > 0) {
		if (checkSyntax(len) == 1) {
			res = "OK";
		} else {
			res = "WRONG";
		}
	}

	printf("%s\n", res);

	return 0;

}