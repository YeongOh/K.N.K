#include <stdio.h>

#define N 50

int main(void) {
	char sentence[N];

	printf("Enter a sentence: ");
	int len;
	char terminating_char;
	for (len = 0; len < N; len++) {
		char c = getchar();
		if (c == '?' || c == '!' || c == '?') {
			terminating_char = c;
			break;
		} else {
			sentence[len] = c;
		}
	}

	printf("Reversal of sentence: ");
	while (len >= 0) {
		int curr;
		for (curr = len; curr >= 0; curr--) {
			if (sentence[curr] == ' ') {
				break;
			}
		}
		for (int i = curr; i <= len; i++) {
			printf("%c", sentence[i]);
		}
		len = curr - 1;
	}
	printf("%c\n", terminating_char);

	return 0;
}
