#include <stdio.h>
#include <ctype.h>

int main(void) {
	printf("Enter a setence: ");
	char c;
	int vowels = 0;

	while ((c = getchar()) != '\n') {
		c = toupper(c);
		if (c == 'A' || c == 'E' || c == 'I' ||
			c == 'O' || c == 'U') {
			vowels++;
		}
	}

	printf("Your sentence contains %d vowels.\n", vowels);

	return 0;
}
