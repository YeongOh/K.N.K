#include <stdio.h>
#include <math.h>

int main(void) {
	double amount, result, interest;
	int years, i;
	
	
	printf("Enter the original amount deposited: ");
	scanf("%lf", &amount);

	printf("Enter the interest rate: ");
	scanf("%lf", &interest);

	printf("Enter the number of years: ");
	scanf("%d", &years);

	interest = interest / 100;
	result = amount * exp(interest * years);

	printf("Amount is %.2f\n", result);


	return 0;
}
