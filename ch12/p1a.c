#include <stdio.h>

#define N 50

int main(void) {
	int arr[N], i = 0;
	char ch;
	printf("Enter a message: ");
	while ((ch = getchar()) != '\n') {
		arr[i] = ch;
		i++;
	}
	i--;

	printf("Reversal is: ");
	for (; i >= 0; i--) {
		printf("%c", arr[i]);
	}
	printf("\n");

	return 0;
}
