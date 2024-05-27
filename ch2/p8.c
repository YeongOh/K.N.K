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

	balance = (balance - monthly) + (balance * ((interest / 12) / 100));
	printf("Balance remaining after first payment: %.2f\n", balance);
	balance = (balance - monthly) + (balance * ((interest / 12) / 100));
	printf("Balance remaining after second payment: %.2f\n", balance);
	balance = (balance - monthly) + (balance * ((interest / 12) / 100));
	printf("Balance remaining after third payment: %.2f\n", balance);
	return 0;
}
