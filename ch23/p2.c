#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	char ch;

	while ((ch = getc(stdin)) != EOF) {
		if (ch == '\n') {
			putc(ch, stdout);
		} else if (!isspace(ch)) {
			putc(ch, stdout);
		}
	}

	return 0;
}
