#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 20

bool are_anagrams(const char *word1, const char *word2);

int main(void) {
	char word1[N + 1];
	char word2[N + 1];

	printf("Enter the first word: ");
	scanf("%20s", word1);
	printf("Enter the second word: ");
	scanf("%20s", word2);

	bool isAnagram = are_anagrams(word1, word2);
	if (isAnagram) {
		printf("The words are anagrams.\n");
	} else {
		printf("The words are not anagrams.\n");
	}

	return 0;
}


bool are_anagrams(const char *word1, const char *word2) {
	int counter[26] = {0};
	char ch;

	while (*word1) {
		ch = tolower(*word1);
		counter[ch - 'a']++;
		word1++;
	}
	
	while (*word2) {
		ch = tolower(*word2);
		counter[ch - 'a']--;
		word2++;
	}
	
	for (int i = 0; i < 26; i++) {
		if (counter[i] != 0) {
			return false;
		}
	}

	return true;
}
