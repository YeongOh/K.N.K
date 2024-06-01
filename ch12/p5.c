#include <stdio.h>

#define N 50

int main(void) {
	char sentence[N];
	char *p;

	printf("Enter a sentence: ");
	int len;
	char terminating_char;
	for (p = sentence; p < p + N; p++) {
		char c = getchar();
		if (c == '?' || c == '!' || c == '?') {
			terminating_char = c;
			break;
		} else {
			*p = c;
		}
	}
	p--;

	printf("Reversal of sentence: ");
	while (p >= sentence) {
		char *curr;
		for (curr = p; curr >= sentence; curr--) {
			if (*curr == ' ') {
				break;
			}
		}
		
		for (char* i = curr; i <= p; i++) {
			printf("%c", *i);
		}
		p = curr - 1;
	}
	printf("%c\n", terminating_char);

	return 0;
}
