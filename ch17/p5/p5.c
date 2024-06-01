#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 60
#define N 20

int read_line(char str[], int n);
int compare(const void *p, const void *q);

int main(void) {
	char *words[MAX_WORDS];
	int i = 0, j;

	while (1) {
		char input[N];
		printf("Enter word: ");
		int len = read_line(input, N);

		if (len == 0) {
			break;
		}
		
		if ((words[i] = malloc(len + 1)) == NULL) {
			printf("Not enough memory\n");
			exit(EXIT_FAILURE);
		}

		strcpy(words[i], input);
		i++;
	}

	qsort(words, i, sizeof(char *), compare);

	printf("In sorted order: ");
	for (j = 0; j < i; j++) {
		printf("%s ", words[j]);
	}
	printf("\n");


	return 0;
}

int read_line(char str[], int n) {
	int i = 0;
	int ch;

	while ((ch = getchar()) != '\n') {
		if (i < n) {
			str[i++] = ch;
		}
	}
	if (i == 0) {
		return i;
	}

	str[i] = 0;
	return i;
}

int compare(const void *p, const void *q) {
	return strcmp(*(char **)p, *(char **)q); 
}
