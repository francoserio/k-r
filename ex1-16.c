#include <stdio.h>

/* print longest input line */

#define MAXLINE 10

/* maximum input line size */
int getlines(char line[], int maxline);
void copy(char to[], char from[]);


/* getline: read a line into s, return length. Getline is reserved so changed name for getlineS */
int getlines(char s[], int lim) {
	int c, i;
	int j = 0;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	j = i;
	if (i == lim-1) {
		if (c == '\n') {
			s[i] = c;
			++i;
		} else {	
			while ((c = getchar()) != EOF && c != '\n') {
				++j;
			}
		}		
	}
	
	s[i] = '\0';

	if (j == 0) {
		return i;
	} else {
		return j;
	}	
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}

int main() {
	int len;
	int max;

	char line[MAXLINE];
	char longest[MAXLINE];
	/* current line length */
	/* maximum length seen so far */
	/* current input line */
	/* longest line saved here */
	max = 0;
	while ((len = getlines(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("%s %d\n", longest, max);	
	}
	return 0;

}