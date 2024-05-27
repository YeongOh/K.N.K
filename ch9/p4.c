#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void) {
	int counts1[26] = {0};
	int counts2[26] = {0};
	printf("Enter the first word: ");
	read_word(counts1);
	
	printf("Enter the second word: ");
	read_word(counts2);
	
	bool isAnagram = equal_array(counts1, counts2);

	if (isAnagram) {
		printf("The words are anagrams.\n");
	} else {
		printf("The words are not anagrams.\n");
	}
	return 0;
}

void read_word(int counts[26]) {
	char ch;
	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			ch = tolower(ch);
			counts[ch - 'a']++;
		}
	}
}

bool equal_array(int counts1[26], int counts2[26]) {
	for (int i = 0; i < 26; i++) {
		if (counts1[i] != counts2[i]) {
			return false;
		}
	}
	return true;
}
