#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp, *op;
	unsigned char output_name[FILENAME_MAX - 4];
	unsigned char buff[BUFSIZ], temp[BUFSIZ * 2];
	unsigned char streak, curr;
	size_t n, l, r;

	if (argc != 2) {
		fprintf(stderr, "usage: compress_file original-file");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open the file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	strcpy(output_name, argv[1]);
	strcat(output_name, ".rle");
	op = fopen(output_name, "wb");
	if (op == NULL) {
		fprintf(stderr, "cannot open the file %s", output_name); 
		exit(EXIT_FAILURE);
	}

	while ((n = fread(buff, sizeof(buff[0]), sizeof(buff) / sizeof(buff[0]), fp)) > 0) {
		streak = 1;
		curr = buff[0];
		l = 0, r = 0;
		while (r < n) {
			if (r + 1 != n && curr == buff[r + 1]) {
				streak++;
			} else {
				temp[l] = streak; 
				temp[l + 1] = curr;
				l = l + 2;

				curr = buff[r + 1];
				streak = 1;
			}
			r++;
		}

		fwrite(temp, sizeof(temp[0]), l, op);
	}

	fclose(fp);
	fclose(op);
	return 0;
}
