#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define N 50

bool is_palindrome(const char *message);
int read_line(char *str, int n);

int main(void) {
	char message[N + 1];
	printf("Enter a message: ");
	read_line(message, N);
	
	if (is_palindrome(message)) {
		printf("It is a palindrome\n");
	} else {
		printf("It is not a palindrome\n");
	}
	return 0;
}

bool is_palindrome(const char *message) {
	const char *l = message;
	const char *r = message + strlen(message) - 1;

	while (l <= r) {
		if (tolower(*l) != tolower(*r)) {
			return false;
		}
		l++;
		r--;
	}
	return true;
}

int read_line(char *str, int n) {
	int i = 0;
	char ch;

	while ((ch = getchar()) != '\n') {
		if (!isalpha(ch)) {
			continue;
		}
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = 0;
	return i;
}
