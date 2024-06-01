#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int total = 0;
	char **p;

	for (p = &argv[argc - 1]; p != &argv[0]; p--) {
		total += atoi(*p);
	}
	printf("Total: %d\n", total);

	return 0;
}
