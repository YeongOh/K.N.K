#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
	int counter[26] = {0};
	printf("Enter the first word: ");
	char ch;
	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			ch = tolower(ch);
			counter[ch - 'a']++;
		}
	}
	
	printf("Enter the second word: ");
	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			ch = tolower(ch);
			counter[ch - 'a']--;
		}
	}
	
	bool isAnagram = true;
	for (int i = 0; i < 26; i++) {
		if (counter[i] != 0) {
			isAnagram = false;
			break;
		}
	}

	if (isAnagram) {
		printf("The words are anagrams.\n");
	} else {
		printf("The words are not anagrams.\n");
	}
	return 0;
}

