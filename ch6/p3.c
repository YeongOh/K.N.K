#include <stdio.h>

int main(void) 
{
	int numerator, denominator;
	printf("Enter a fraction (d/d): ");
	scanf("%d/%d", &numerator, &denominator);

	if (numerator >= denominator) {
		printf("A fraction can't be greater than or equal to 1.\n");
		return 0;
	}

	int n = numerator;
	int m = denominator;
	while (n != 0) {
		int remainder = m % n;
		m = n;
		n = remainder;
	}
	
	printf("In lowest terms: %d/%d\n", numerator / m, denominator / m);
	
	return 0;
}
