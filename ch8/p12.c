#include <stdio.h>
#include <ctype.h>

int main(void) {
	printf("Enter a word: ");
	char ch;
	int values[26] = {0};

	while ((ch = getchar()) != '\n') {
		ch = toupper(ch);
		switch (ch) {
			case 'D': values[ch - 'D'] += 2; break;
			case 'G': values[ch - 'G'] += 2; break;
			case 'B': values[ch - 'B'] += 3; break; 
			case 'C': values[ch - 'C'] += 3; break;
			case 'M': values[ch - 'M'] += 3; break;
			case 'P': values[ch - 'P'] += 3; break;
			case 'F': values[ch - 'F'] += 4; break;
			case 'H': values[ch - 'H'] += 4; break;
			case 'V': values[ch - 'V'] += 4; break;
			case 'W': values[ch - 'W'] += 4; break;
			case 'Y': values[ch - 'Y'] += 4; break;
			case 'K': values[ch - 'K'] += 5; break;
			case 'J': values[ch - 'J'] += 8; break;
			case 'X': values[ch - 'X'] += 8; break;
			case 'Q': values[ch - 'Q'] += 10; break;
			case 'Z': values[ch - 'Z'] += 10; break;
			default: values[ch - 'A']++; break;
		}	
	}

	int result = 0;
	for (int i = 0; i < 26; i++) {
		result += values[i];
	}
	printf("Scrabble value: %d\n", result);

	return 0;
}
