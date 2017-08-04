#include <stdio.h>

/* print longest input line */

#define MAXLINE 1000
#define PRINT 80

/* maximum input line size */
int getlines(char line[], int maxline);
void copyReverse(char to[], char from[], int len);


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
		} else 	{
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

/* copyReverse: copyReverse 'from' into 'to'; assume to is big enough */
void copyReverse(char to[], char from[], int l) {
	int i = 0;
	while (from[i] != '\0') {
		to[i] = from[l-i-1];
		++i;
	}
}

int main() {
	int len;
	// int max;

	char line[MAXLINE];
	char reverse[MAXLINE];
	/* current line length */
	/* maximum length seen so far */
	/* current input line */
	/* longest line saved here */
	// max = 0;
	while ((len = getlines(line, MAXLINE)) > 0) {
		// if (len > max) {
		// 	max = len;
		copyReverse(reverse, line, len);
		// }
		printf("%s\n", reverse);
	}

	// if (max > 0) {
	// 	printf("%s %d\n", longest, max);	
	// }
	return 0;

}