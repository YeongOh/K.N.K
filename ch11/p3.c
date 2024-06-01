#include <stdio.h>

void reduce(int numerator, int denominator,
			int *reduced_numerator,
			int *reduced_denominator);

int main(void) 
{
	int numerator, denominator;
	printf("Enter a fraction (d/d): ");
	scanf("%d/%d", &numerator, &denominator);

	if (numerator >= denominator) {
		printf("A fraction can't be greater than or equal to 1.\n");
		return 0;
	}

	int reduced_numerator, reduced_denominator;

	reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
	
	printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);
	
	return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
	int n = numerator;
	int m = denominator;

	while (n != 0) {
		int remainder = m % n;
		m = n;
		n = remainder;
	}

	*reduced_numerator = numerator / m;
	*reduced_denominator = denominator / m;
}
