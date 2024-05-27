#include <stdio.h>
#include <ctype.h>

int main(void) {
	char c;
	char lastname_initial;

	// last name
	while ((c = getchar()) == ' ');
	lastname_initial = toupper(c);

	while (getchar() != ' ');
	while ((c = getchar()) == ' ');

	putchar(toupper(c));
	while ((c = getchar()) != ' ') {
		if (c == '\n') {
			break;
		}
		putchar(c);
	}

	printf(", %c.\n", lastname_initial);

	return 0;
}
