#include <stdio.h>

int main() {

	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("%s", "\\t");
		} else if (c == '\b') {
			printf("%s", "\\b");
		} else if (c == '\\') {
			printf("%s", "\\\\");
		} else {
			putchar(c);	
		}
	}
	//to enter a backspace in console do ctrl-H
	return 0;
}