#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

int main(void) {
	FILE *fp, *op;
	unsigned char filename[FILENAME_MAX];
	int ch, shift;

	printf("Enter name of file to be encrypted: ");
	scanf("%s", filename); 
	fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s", filename);
		exit(EXIT_FAILURE);
	}

	op = fopen(strcat(filename, ".enc"), "w");
	if (op == NULL) {
		fprintf(stderr, "cannot open %s", filename);
		exit(EXIT_FAILURE);
	}

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	while ((ch = getc(fp)) != EOF) {
		if (isupper(ch)) {
			ch = (ch - 'A' + shift) % 26 + 'A';
		} else if (islower(ch)) {
			ch = (ch - 'a' + shift) % 26 + 'a';
		} 
		putc(ch, op); 
	}

	fclose(fp);
	fclose(op);
	return 0;
}
