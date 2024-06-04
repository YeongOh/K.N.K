#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int ch;
	int count = 0;
	bool is_word;

	if (argc != 2) {
		fprintf(stderr, "usage: countwords filename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "%s could not be opened", argv[1]);
		exit(EXIT_FAILURE);
	}

	is_word = false;
	while ((ch = getc(fp)) != EOF) {
		if (isspace(ch)) {
			is_word = false;
			continue;
		}		
		if (is_word == false) {
			is_word = true;
			count++;
		}
	}

	printf("There are %d words in %s.\n", count, argv[1]);

	fclose(fp);
	return 0;
}
