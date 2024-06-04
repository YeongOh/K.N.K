#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main(int argc, char *argv[]) {
	FILE *fp;
	unsigned char buff[N];
	size_t offset = 0, i = 0, n = 0;
	if (argc != 2) {
		fprintf(stderr, "usage: display filename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	

	printf("Offset             Bytes              Characters\n");
	printf("-----  -----------------------------  ----------\n");
	while ((n = fread(buff, sizeof(buff[0]), sizeof(buff) / sizeof(buff[0]), fp)) > 0) {
		// Offset
		printf("%5ld", offset);
		printf("  ");

		// Bytes
		for (i = 0; i < n; i++) {
			printf("%2.2X ", buff[i]);
		}
		printf(" ");
		
		for (; i < N; i++) {
			printf("   ");
		}

		// Characters
		for (i = 0; i < n; i++) {
			if (isprint(buff[i])) {
				printf("%c", buff[i]);
			} else {
				printf(".");
			}
		}
		printf("\n");
		offset += 10;
		memset(buff, 0, sizeof(buff) / sizeof(buff[0]));
	}

	fclose(fp);
	return 0;
}
