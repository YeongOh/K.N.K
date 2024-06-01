#include <stdio.h>
#include <ctype.h>

#define N 80

void encrypt(char *message, int shift);
int read_line(char *message, int n);

int main(void) {
	char message[N + 1];
	char ch;
	printf("Enter message to be encrypted: ");
	read_line(message, N);
	
	int shift;
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);
	encrypt(message, shift);

	printf("Encrypted message: %s\n", message);

	return 0;
}

void encrypt(char *message, int shift) {
	for (; *message; message++) {
		char c = *message;
		if (isupper(c)) {
			*message = (c - 'A' + shift) % 26 + 'A';
		} else if (islower(c)) {
			*message = (c - 'a' + shift) % 26 + 'a';
		}
	}
}

int read_line(char *message, int n) {
	int i = 0;
	char ch;

	while ((ch = getchar()) != '\n') {
		if (i < n) {
			message[i++] = ch;
		}
	}
	message[i] = 0;

	return i;

}
