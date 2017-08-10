#include <stdio.h>

#define NTHCOLUMN 14
#define MAXLINE 1000


int getlines(void);
void replaceAndCopy(int le);

char line[MAXLINE];
char result[MAXLINE][MAXLINE];
int j;

void foldAndCopy(int len) {

	extern char line[];
	extern char result[MAXLINE][MAXLINE];
	extern int j;

	int i = 0;
	
	j = 0;
	int lastBlank = 0;
	int lastLastBlank = 0;
	while (i < len) {
		if (i % NTHCOLUMN == 0) {
			// printf("%d\n", i);
			int resultCounter = 0;
			int p;
			if (lastLastBlank != 0) {
				p = lastLastBlank + 1;
			} else {
				p = lastLastBlank;
			}
			while (p < lastBlank) {
				result[j][resultCounter] = line[p];
				++resultCounter;
				++p;
			}
			++j;
			lastLastBlank = lastBlank;
		}
		if (line[i] == ' ' || line[i] == '\t') {
			lastBlank = i;
		}
		++i;
	}
	// printf("%s %d\n", "last blank", lastBlank);
	int h = 0;
	int m;
	if (lastLastBlank == lastBlank) {
		m = lastLastBlank + 1;
	}  else {
		m = lastLastBlank;
	}
	while (m < len) {
		// printf("%s %d %c %d\n", "m is", m, line[m], j);
		result[j][h] = line[m];
		++h;
		++m;
	}
	// printf("%s\n", result[1]);
}

int getlines(void) {
	int c;
	int i;
	
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF; ++i) {
		line[i] = c;
	}
	line[i] = '\0';

	return i+1;
}

int main() {

	int len;

	extern int j;
	extern char result[MAXLINE][MAXLINE];

	if ((len = getlines()) > 0) {
		foldAndCopy(len);
	}

	// printf("%d\n", j);
	for (int i = 0; i <= j; ++i) {
		printf("%s\n", result[i]);
	}

	return 0;
}