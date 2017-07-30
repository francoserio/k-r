#include <stdio.h>
#define IN 1
#define OUT 0

/* inside a word */
/* outside a word */
/* count lines, words, and characters in input */

int main ()
{
	int c;
	// int c, nl, nw, nc, state;
	// state = OUT;
	// nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		// ++nc;
		// if (c == '\n') {
		// 	++nl;
		// }
		if (c == ' ' || c == '\n' || c == '\t') {
			putchar('\n');
		}
		else {
			putchar(c);	
		}
	}
	// printf("%d %d %d\n", nl, nw, nc);
}