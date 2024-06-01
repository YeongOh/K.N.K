#include <stdio.h>
#include <ctype.h>

#define N 50

int main(void) {
	int arr[N], *p;
	char ch;

	printf("Enter a message: ");
	for (p = arr; p < arr + N; p++) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		if (!isalpha(ch)) {
			p--;
			continue;
		}
		*p = tolower(ch);
	}
	p--;
	int *len = p;
	int *mid = arr + (p - arr) / 2;

	for (; p > mid; p--) {
		if (*(arr + (len - p)) != *p) {
			printf("Not a palindrome.\n");
			return 0;
		}
	}

	printf("Palindrome.\n");

	

	return 0;
}
