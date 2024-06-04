#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int item_number;
	float unit_price;
	int month, day, year;
	FILE *fp;
	char buf[BUFSIZ];

	if (argc != 2) {
		fprintf(stderr, "usage: display filename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Item    Unit            Purchase\n");
	printf("        Price           Date\n");
	while (fgets(buf, BUFSIZ, fp) != NULL) {
		sscanf(buf, "%d,%f,%d/%d/%d", &item_number, &unit_price, &month, &day, &year);
		printf("%-6d  $%8.2f       %d/%.2d/%d\n", item_number, unit_price, month, day, year);
	}

	fclose(fp);
	return 0;
}
