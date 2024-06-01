#include <stdio.h>
#include <ctype.h>

#define N 50

int compute_scrabble_value(const char *word);

int main(void) {
	char word[N + 1];

	printf("Enter a word: ");
	scanf("%s", word);

	printf("Scrabble value: %d\n", compute_scrabble_value(word));

	return 0;
}

int compute_scrabble_value(const char *word) {
	int val = 0;

	while (*word) {
		switch (toupper(*word++)) {
			case 'D': case 'G':
				val += 2; break;
			case 'B': case 'C':
			case 'M': case 'P':
				val += 3; break;
			case 'F': case 'H': case 'V':
			case 'W': case 'Y':
				val += 4; break;
			case 'K':
				val += 5; break;
			case 'J': case 'X':
				val += 8; break;
			case 'Q': case 'Z':
				val += 10; break;
			default:
				val++; break;
		}
	}

	return val;
}
