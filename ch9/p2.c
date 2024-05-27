#include <stdio.h>

float calculate_tax(int income);

int main(void) 
{
	int income;
	printf("Enter your taxable income: ");
	scanf("%d", &income);

	printf("Your tax due is $%.2f.\n", calculate_tax(income));

	return 0;
}

float calculate_tax(int income) {
	float result;
	if (income < 750) {
		result = income * 0.01; 
	} else if (income < 2250) {
		result = 7.50f + (income - 750) * 0.02f;
	} else if (income < 3750) {
		result = 37.50f + (income - 2250) * 0.03f;
	} else if (income < 5250) {
		result = 82.50f + (income - 3750) * 0.04f;
	} else if (income < 7000) {
		result = 142.50f + (income - 5250) * 0.05f;
	} else {
		result = 230.00f + (income - 7000) * 0.06f;
	}

	return result;
}
