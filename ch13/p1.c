#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(void) {
	char largest_word[MAX_LEN + 1];
	char smallest_word[MAX_LEN + 1];
	char curr[MAX_LEN + 1];

	printf("Enter word: ");
	scanf("%20s", curr);
	strcpy(largest_word, strcpy(smallest_word, curr));

	while (strlen(curr) != 4) {
		printf("Enter word: ");
		scanf("%20s", curr);
		
		if (strcmp(largest_word, curr) < 0) {
			strcpy(largest_word, curr);
		} else if (strcmp(smallest_word, curr) > 0) {
			strcpy(smallest_word, curr);
		}
	}

	printf("Smallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
