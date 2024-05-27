#include <stdio.h>

int main(void) 
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	int reverse = 0;
	while (n > 0) {
		reverse *= 10;
		reverse += n % 10;
		n /= 10;		
	}

	printf("The reversal is %d\n", reverse);

	return 0;
}

