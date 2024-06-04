#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_COUNT 50

int main(void) {
	char buf[BUFSIZ];
	char *words[MAX_WORD_COUNT];
	char *pt;
	int i = 0;

	printf("Enter a series of words separated by single spaces.\n");
	fgets(buf, BUFSIZ - 1, stdin); 
	// replace newline char
	buf[strlen(buf) - 1] = 0;

	words[i++] = strtok(buf, " ");
	while ((words[i] = strtok(NULL, " ")) != NULL){
		i++;
	}; 
	i--;

	for (; i >= 0; i--) {
		printf("%s ", words[i]);
	}
	printf("\n");

	return 0;
}
