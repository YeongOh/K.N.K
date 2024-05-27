#include <stdio.h>
#include <ctype.h>

int main(void) {
	char c;
	char lastname[20];

	// last name
	while ((c = getchar()) == ' ');
	int len = 1;
	lastname[0] = c;

	while ((c = getchar()) != ' ') {
		lastname[len] = c;
		len++;
	}
	while ((c = getchar()) == ' ');

	putchar(toupper(c));
	while ((c = getchar()) != ' ') {
		if (c == '\n') {
			break;
		}
		putchar(c);
	}

	printf(", %c.\n", toupper(lastname[0]));

	return 0;
}
