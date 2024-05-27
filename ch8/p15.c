#include <stdio.h>
#include <ctype.h>

#define N 80

int main(void) {
	char message[N];
	char ch;
	printf("Enter message to be encrypted: ");

	int len = 0;
	while ((ch = getchar()) != '\n') {
		message[len] = ch;
		len++;
	}

	int shift;
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	printf("Encrypted message: ");
	for (int i = 0; i < len; i++) {
		char c = message[i];
		if (isupper(c)) {
			printf("%c", (c - 'A' + shift) % 26 + 'A');
		} else if (islower(c)) {
			printf("%c", (c - 'a' + shift) % 26 + 'a');
		} else {
			printf("%c", c);
		}
	}
	printf("\n");

	return 0;
}
