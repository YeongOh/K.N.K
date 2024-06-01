#include <stdio.h>
#include <string.h>

#define N 50

// Ch13. Q16

void reverse(char *message);
int read_line(char *str, int n);

int main(void) {
	printf("Enter a message: ");
	char message[N + 1];
	read_line(message, N);

	reverse(message);
	printf("reverse is: %s\n", message);
	return 0;
}

void reverse(char *message) {
	int len = strlen(message);
	char *l = message;
	char *r = message + len - 1;

	for (; l <= r; l++, r--) {
		char temp = *l;
		*l = *r;
		*r = temp;
	}
}

int read_line(char *str, int n) {
	int i = 0;
	int ch;
	while ((ch = getchar()) != '\n') {
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = 0;

	return i;
}
