#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	unsigned char str[10];
	int a, b, c;
	int i = 0, ch;

	if (argc != 2) {
		fprintf(stderr, "usage: tel filename");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "%s could not be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			printf("(%c%c%c) %c%c%c-%c%c%c%c\n",
					str[0], str[1], str[2],
					str[3], str[4], str[5],
					str[6], str[7], str[8], str[9]);
			i = 0;
			continue;
		}
		if (isdigit(ch)) {
			str[i++] = ch;
		}
	}

	fclose(fp);
	return 0;
}
