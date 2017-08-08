#include <stdio.h>

#define TABSTOPS 8
#define MAXLINE 1000
#define YES 1
#define NO 0


int getlines(void);
void replaceAndCopy(int le);

char line[MAXLINE];
char result[MAXLINE];

int fromBlankToTabStop(int i) {
	extern char line[];
	int j;
	int result;

	int iGuardado = i;
	while (line[iGuardado] == ' ' || line[iGuardado] == '\t') {
		++iGuardado;
	}

	int res = NO;
	for (j = i; j <= iGuardado && res == NO; ++j) {
		if (j != 0 && j % TABSTOPS == 0) {
			res = YES;
			result = j;
		}
	}
	// printf("%d %d\n", iGuardado, j);
	return result - i;

}

int fromBlankToChar(int i) {
	extern char line[];
	// int j;

	int iGuardado = i;
	while (line[iGuardado] == ' ' || line[iGuardado] == '\t') {
		++iGuardado;
	}

	// int res = NO;
	// for (j = i; j <= iGuardado && res == NO; ++j) {
	// 	if (j != 0 && j % TABSTOPS == 0) {
	// 		res = YES;
	// 	}
	// }
	// printf("%d %d\n", iGuardado, j);
	return iGuardado - i;
}

int untilNextTabStop(int i) {
	extern char line[];

	int iGuardado = i;
	while (line[iGuardado] == ' ' || line[iGuardado] == '\t') {
		++iGuardado;
	}

	int res = NO;
	if (i != iGuardado) {
		for (int j = i+1; j <= iGuardado && res == NO; ++j) {
			if (j != 0 && j % TABSTOPS == 0) {
				res = YES;
			}
		}
	}

	printf("%d %d %d\n", i, iGuardado, res);

	return res;
}


void replaceAndCopy(int l) {

	extern char line[];
	extern char result[];

	int i = 0;
	int j = 0;
	while (i < l) {
		if (line[i] != ' ' && line[i] != '\t') {
			result[j] = line[i];
			++i;
			++j;
		} else {
			// printf("%d %s\n", pepe, "pepe");
			if (untilNextTabStop(i)) {
				int pepe = fromBlankToChar(i);
				int pepe2 = fromBlankToTabStop(i);
				int p = i;
				while (untilNextTabStop(i)) {
					result[j] = '\t';
					++j;
					i = i + pepe2;
				}
				while (i < p + pepe) {
					result[j] = ' ';
					++i;
					++j;
				}
			} else {
				result[j] = ' ';
				++i;
				++j;
			}
		}
	}

}


int getlines(void) {
	int c;
	int i;
	
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF; ++i) {
		line[i] = c;
	}
	line[i] = '\0';

	return i;
}


int main() {

	int len;
	extern char result[];

	if ((len = getlines()) > 0) {
		replaceAndCopy(len);
	}

	printf("%s\n", result);

	return 0;
}