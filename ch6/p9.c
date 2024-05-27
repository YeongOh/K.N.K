#include <stdio.h>

int main(void) 
{
	float balance;
	printf("Enter amount of loan: ");
	scanf("%f", &balance);

	float interest;
	printf("Enter interest rate: ");	
	scanf("%f", &interest);
	
	float monthly;
	printf("Enter monthly payment: ");
	scanf("%f", &monthly);

	int number_of_payments;
	printf("Enter number of payments: ");
	scanf("%d", &number_of_payments);

	for (int i = 0; i < number_of_payments; i++) {
		balance = (balance - monthly) + (balance * ((interest / 12) / 100));
		printf("Balance remaining after payment %d: %.2f\n", i + 1, balance);
	}

	return 0;
}
