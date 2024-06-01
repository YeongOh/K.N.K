#include <stdio.h>
#include <ctype.h>

#define N 50
#define WORD_COUNT 30
#define WORD_LEN 20

int read_line(char words[WORD_COUNT][WORD_LEN + 1], int n);

int main(void) {
	char words[WORD_COUNT][WORD_LEN + 1];
	char sentence[N];

	printf("Enter a sentence: ");
	int word_count = read_line(words, WORD_COUNT * WORD_LEN);
	for (int i = word_count - 2; i >= 0 ; i--) {
		if (i == 0) {
			printf("%s", words[i]);
		} else {
			printf("%s ", words[i]);
		}
	}
	printf("%s", words[word_count - 1]);
	printf("\n");

	return 0;
}

int read_line(char words[WORD_COUNT][WORD_LEN + 1], int n) {
	int word_i = 0;
	int char_i = 0;
	int ch;

	while ((ch = getchar())) {
		if (ch == '!' || ch == '?' || ch == '.') {
			words[word_i][char_i] = 0;
			word_i++;
			words[word_i][0] = ch;
			char_i = 1;
			break;
		}
		if (isspace(ch)) {
			words[word_i][char_i] = 0;
			char_i = 0;
			word_i++;
			continue;
		}
		if (word_i * char_i < n) {
			words[word_i][char_i] = ch; 
			char_i++;
		}
	}
	words[word_i][char_i] = 0;

	return word_i + 1;
}
