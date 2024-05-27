#include <stdio.h>

int main(void) {
	int largest = 0;

	while (1) {
		int input;
		printf("Enter a number: ");
		scanf("%d", &input);
	
		if (input == 0) {
			break;
		}

		if (largest < input) {
			largest = input;
		}
	}

	printf("The largest number entered was %d\n", largest);
	return 0;
}
