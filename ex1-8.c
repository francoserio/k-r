#include <stdio.h>

int main() {

	int tabs = 0;
	int blanks = 0;
	int newlines = 0;
	int c;
	while((c = getchar()) != EOF) {
		if (c == '\n') {
			++newlines;
		}
		if (c == '\t') {
			++tabs;
		}
		if (c == ' ') {
			++blanks;
		}
	}

	printf("%s\n", "newlines: ");
	printf("%d\n", newlines);
	printf("%s\n", "tabs: ");
	printf("%d\n", tabs);
	printf("%s\n", "blanks: ");
	printf("%d\n", blanks);

	//remember ctrl + d to make an EOF

	return 0;
}