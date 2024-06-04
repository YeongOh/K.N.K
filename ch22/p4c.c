#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int ch, count = 0;

	if (argc != 2) {
		fprintf(stderr, "usage: numlines filename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') {
			count++;
		}
	}

	printf("There are %d lines in %s.\n", count, argv[1]);

	fclose(fp);
	return 0;
}
