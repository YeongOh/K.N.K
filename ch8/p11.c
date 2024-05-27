#include <stdio.h>

#define N 15

int main(void)
{
	char phone_number[N];
	printf("Enter phone number: ");

	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n') {
		if (ch >= 'A' && ch <= 'Z') {
			phone_number[i] = (((ch - 'A') / 3) + 2) + '0'; 
		} else {
			phone_number[i] = ch;
		}
		i++;
	}
	phone_number[i] = '\0';

	for (int j = 0; j < N; j++) {
		if (phone_number[j] == '\0') {
			break;
		}
		printf("%c", phone_number[j]);
	}
	printf("\n");

	return 0;
}
