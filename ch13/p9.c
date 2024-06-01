#include <stdio.h>
#include <ctype.h>

#define STR_LEN 80

int compute_vowel_count(const char *sentence);
int read_line(char str[], int n); 

int main(void) {
	printf("Enter a setence: ");
	char sentence[STR_LEN + 1]; 
	read_line(sentence, STR_LEN);

	printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

	return 0;
}

int compute_vowel_count(const char *sentence) {
	int result = 0;
	char c; 

	while (*sentence) {
		c = toupper(*sentence);
		if (c == 'A' || c == 'E' || c == 'I' ||
			c == 'O' || c == 'U') {
			result++;
		}
		sentence++;
	}

	return result;
}

int read_line(char str[], int n) {
	int i = 0;
	int ch;

	while ((ch = getchar()) != '\n') {
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = 0;

	return i;
}
