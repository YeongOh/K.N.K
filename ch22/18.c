#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

int comp(const void *, const void *);

int main(int argc, char *argv[]) {
	FILE *fp;
	int arr[N], i, temp;
	char buff[BUFSIZ];

	if (argc != 2) {
		fprintf(stderr, "usage: num filename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (fscanf(fp, "%d", &arr[i]) == 1) {
		i++;
	}

	qsort(arr, i, sizeof(int), comp);
	printf("max: %d\nmin: %d\nmedian: %d\n", 
			arr[i - 1], arr[0], 
			i % 2 == 0 ? (arr[i / 2] + arr[i / 2 + 1]) / 2 : arr[i / 2]); 

	fclose(fp);
	return 0;
}

int comp(const void * p, const void * q) {
	return *((int *)p) - *((int *)q);
}
