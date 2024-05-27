#include <stdio.h>

int main(void)
{
	int amount;
	printf("Enter a dollar amount: ");
	scanf("%d", &amount);

	int twenty = amount / 20;
	amount %= 20;
	int ten = amount / 10;
	amount %= 10;
	int five = amount / 5;
	amount %= 5;
	
	printf("$20 bills: %d\n", twenty);
	printf("$10 bills: %d\n", ten);
	printf("$5 bills: %d\n", five);
	printf("$1 bills: %d\n", amount);
	return 0;
}
