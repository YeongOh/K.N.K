#include <stdio.h>

int main(void)
{
	printf("Enter phone number: ");

	char ch;
	while ((ch = getchar()) != '\n') {
		if (ch >= 'A' && ch <= 'Z') {
			printf("%d", ((ch - 'A') / 3) + 2);
		} else {
			putchar(ch);
		}
	}
	putchar('\n');

	return 0;
}
