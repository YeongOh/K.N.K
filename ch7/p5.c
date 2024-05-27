#include <stdio.h>
#include <ctype.h>

int main(void) {
	printf("Enter a word: ");
	char ch;
	int val = 0;

	while ((ch = getchar()) != '\n') {
		switch (toupper(ch)) {
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
	printf("Scrabble value: %d\n", val);

	return 0;
}
