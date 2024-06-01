#include <stdio.h>
#include <ctype.h>

#define N 50

int main(void) {
	int arr[N];
	int i;
	char ch;

	printf("Enter a message: ");
	for (i = 0; i < N; i++) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		if (!isalpha(ch)) {
			i--;
			continue;
		}
		arr[i] = tolower(ch);
	}
	i--;
	int len = i;

	for (; i > i / 2; i--) {
		if (arr[len - i] != arr[i]) {
			printf("Not a palindrome.\n");
			return 0;
		}
	}

	printf("Palindrome.\n");

	

	return 0;
}
