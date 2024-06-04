#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[]) 
{
	FILE *fp, *op;
	char ext[5], filename[FILENAME_MAX];
	unsigned char buf[10], temp[BUFSIZ]; 
	size_t n, i, j, count;

	size_t len;
	if (argc != 2) {
		fprintf(stderr, "usage: uncompress filename.rle\n");
		exit(EXIT_FAILURE);
	}
	
	len = strlen(argv[1]);
	strncpy(ext, argv[1] + len - 4, 4);
	ext[4] = 0;
	if (strcmp(ext, ".rle") != 0) {
		fprintf(stderr, "filename must end with rle\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "file could not be opened\n");
		exit(EXIT_FAILURE);
	}

	strncpy(filename, argv[1], len - 4);
	filename[len - 3] = 0;
	op = fopen(filename, "wb");
	if (op == NULL) {
		fprintf(stderr, "file could not be created\n");
		exit(EXIT_FAILURE);
	}

	while ((n = fread(buf, sizeof(buf[0]), sizeof(buf) / sizeof(buf[0]), fp)) > 0) {
		j = 0;
		for (i = 0; i < n; i += 2) {
			count = buf[i];
			for (; count > 0; count--) {
				temp[j++] = buf[i + 1];
				printf("%c", buf[i + 1]);
			}
		}
		fwrite(temp, sizeof(temp[0]), j, op);
	}

	fclose(fp);
	fclose(op);
	return 0;
}
