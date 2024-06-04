// counts the number of characters in a text file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int ch, count = 0;

	if (argc != 2) {
		printf("usage: countchar filename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(*(++argv), "r");
	if (fp == NULL) {
		fprintf(stderr, "%s could not be opened\n", *argv);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF) {
		count++;
	}

	printf("The number of characters in %s is %d.\n", *argv, count);

	fclose(fp);
	return 0;
}
