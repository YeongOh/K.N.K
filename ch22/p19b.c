#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp, *op;
	char str[BUFSIZ + 1];
	int len;

	if (argc != 3) {
		fprintf(stderr, "usage: unixtowin inputfile outputfile\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	op = fopen(argv[2], "wb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(str, BUFSIZ - 1, fp) != NULL) {
		len = strlen(str);
		if (str[len - 1] == '\n') {
			str[len - 1] = '\x0d';
			str[len] = '\n';
			str[len + 1] = 0;
		}
		fputs(str, op);
	}

	fclose(op);
	fclose(fp);

	return 0;
}
