#include <stdio.h>

int main(void) {
	int sum = 0;
	int word_count = 0;
	printf("Enter a sentence: ");
	
	char c;
	while ((c = getchar()) != '\n') {
		if (c == ' ') {
			word_count++;
		} else {
			sum++;
		}
	}
	word_count++;

	printf("Average word length: %.1f\n", (float)sum / word_count); 

	return 0;
}
