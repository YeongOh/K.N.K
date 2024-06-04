#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	int count = 0;
	int ch;
	int prev;

	while ((ch = getchar()) != EOF) {
		if (strchr(".?!", prev) != NULL && isspace(ch)) {
			count++;
		}
		prev = ch;
	}

	printf("count: %d\n", count);

	return 0;
}
