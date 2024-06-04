#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int ch;

	if (argc < 2) {
		printf("usage: fcat filename1 filename2 ...\n");
		exit(EXIT_FAILURE);
	}

	for (argv++; *argv != NULL; argv++) {
		if ((fp = fopen(*argv, "r")) == NULL) {
			fprintf(stderr, "file %s could not be opened\n", *argv);
			continue;
		}
		
		while ((ch = getc(fp)) != EOF) {
			putchar(ch);
		}

		fclose(fp);
	}

	return 0;
}
