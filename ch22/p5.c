#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
	FILE *fp, *op;
	char buf[BUFSIZ]; 
	size_t n, i;
	if (argc != 3) {
		fprintf(stderr, "usage: xor inputfilename outputfilename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	op = fopen(argv[2], "wb");
	if (fp == NULL || op == NULL) {
		fprintf(stderr, "could not open %s or create %s\n", argv[1], argv[2]);
	}

	while ((n = fread(buf, sizeof(buf[0]), sizeof(buf) / sizeof(buf[0]), fp)) > 0) {
		for (i = 0; i < n; i++) {
			buf[i] ^= KEY;
		}

		fwrite(buf, sizeof(buf[0]), n, op);
	}

	fclose(fp);
	fclose(op);
	return 0;
}
