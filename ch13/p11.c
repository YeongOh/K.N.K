#include <stdio.h>
#include <ctype.h>

#define N 50

int read_line(char *str, int n);
double compute_average_word_length(const char *sentence);

int main(void) {
	int sum = 0;
	int word_count = 0;
	char sentence[N + 1];
	printf("Enter a sentence: ");
	read_line(sentence, N);

	double average = compute_average_word_length(sentence);
	printf("Average word length: %.1f\n", average);
	
	return 0;
}

double compute_average_word_length(const char *sentence) {
	double sum = 0;
	int word_count = 1;

	while (*sentence) {
		if (isspace(*sentence)) {
			while (isspace(*sentence)) {
				sentence++;
			}
			word_count++;
		} else {
			sum++;
			sentence++;
		}
	}

	return sum / word_count;
}

int read_line(char *str, int n) {
	int i = 0;
	char ch;

	while ((ch = getchar()) != '\n') {
		if (isspace(ch) && i == 0) {
			continue;
		}
		if (i < n) {
			str[i++] = ch;
		}
	}
	int space_remove = i - 1;
	while (isspace(str[space_remove])) {
		space_remove--;
	}
	i = space_remove + 1;
	str[i] = 0;

	return i;
}
