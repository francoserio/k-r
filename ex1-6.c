#include <stdio.h>

int main() {
	int c;
	c = (getchar() != EOF);
	
	printf("%d\n", c);
	//when in terminal press ctrl + D to make an EOF

	return 0;
}