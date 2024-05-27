#include <stdio.h>

int main(void) 
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	if (n >= 0 && n <= 9) {
		printf("The number %d has 1 digit\n", n);
	} else if (n <= 99) {
		printf("The number %d has 2 digit\n", n);
	} else if (n <= 999) {
		printf("The number %d has 3 digit\n", n);
	} else if (n <= 9999) {
		printf("The number %d has 4 digit\n", n);
	} else {
		printf("The number %d has many digit\n", n);
	}

	return 0;
}
