#include <stdio.h>

// short n: 10
// int n: 19 
// long n : 25
// long long n : 25
// float n : 35
// double n : 170, google doesn't show calculations for 171!
// long double n : 1754

int main(void) {
	int n;
	printf("Enter a positive integer: ");
	scanf("%d", &n);

	long double factorial = 1;
	for (int i = n; i > 1; i--) {
		factorial *= i;
	}

	printf("Factorial of 6: %Lf\n", factorial);

	return 0;
}

