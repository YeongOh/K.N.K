#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
};

int num_parts = 0;   /* number of parts currently stored */

int main(int argc, char *argv[]) {
	FILE *ip1, *ip2, *op;
	struct part part1, part2;
	size_t n1, n2;
	
	if (argc != 4) {
		fprintf(stderr, "usage: merge inputfile1 inputfile2 mergedfile\n");
		exit(EXIT_FAILURE);
	}

	if ((ip1 = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "can't find %s for input1\n", argv[1]); 
		exit(EXIT_FAILURE);
	}

	if ((ip2 = fopen(argv[2], "rb")) == NULL) {
		fprintf(stderr, "can't find %s for input2\n", argv[2]); 
		exit(EXIT_FAILURE);
	}

	if ((op = fopen(argv[3], "wb")) == NULL) {
		fprintf(stderr, "can't find %s for output\n", argv[3]); 
		exit(EXIT_FAILURE);
	}

	do {
		n1 = fread(&part1, sizeof(struct part), 1, ip1);
		n2 = fread(&part2, sizeof(struct part), 1, ip2);
		
		if (part1.number > part2.number) {
			fwrite(&part2, sizeof(struct part), 1, op);
			n2 = fread(&part2, sizeof(struct part), 1, ip2);
			continue;
		} 

		if (part1.number < part2.number) {
			fwrite(&part1, sizeof(struct part), 1, op);
			n1 = fread(&part1, sizeof(struct part), 1, ip1);
			continue;
		}

		if (strcmp(part1.name,  part2.name) != 0) {
			fprintf(stderr, "part %d do not have the same name\n", part1.number);
			exit(EXIT_FAILURE);
		}

		part1.on_hand += part2.on_hand;
		fwrite(&part1, sizeof(struct part), 1, op);
		n1 = fread(&part1, sizeof(struct part), 1, ip1);
		n2 = fread(&part2, sizeof(struct part), 1, ip2);
	} while (n1 && n2);

	while (n1) {
		fwrite(&part1, sizeof(struct part), 1, op);
		n1 = fread(&part1, sizeof(struct part), 1, ip1);
	}

	while (n2) {
		fwrite(&part2, sizeof(struct part), 1, op);
		n2 = fread(&part2, sizeof(struct part), 1, ip2);
	}

	fclose(ip1);
	fclose(ip2);
	fclose(op);
	return 0;
}
