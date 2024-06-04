#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {
	int ch;
	bool is_first_word = true;

	while ((ch = getchar()) != EOF) {
		if (islower(ch) && is_first_word) {
			putchar(toupper(ch));
			is_first_word = false;
			continue;
		}
		if (isspace(ch)) {
			putchar(ch);
			is_first_word = true;
			continue;
		}
		putchar(ch);
	}

	return 0;
}
