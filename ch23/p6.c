#include <stdio.h>
#include <ctype.h>

int main(void) {
	int ch;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			putchar(ch);
			continue;
		}
		if (iscntrl(ch)) {
			putchar('?');
			continue;
		}
		putchar(ch);
	}

	return 0;
}
