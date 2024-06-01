#include <stdio.h>

void pay_amount(int dollar, int *twenty, int *ten,
				int *five, int *one);

int main(void)
{
	int amount;
	printf("Enter a dollar amount: ");
	scanf("%d", &amount);

	int twenty, ten, five, one;
	pay_amount(amount, &twenty, &ten, &five, &one);
	
	printf("$20 bills: %d\n", twenty);
	printf("$10 bills: %d\n", ten);
	printf("$5 bills: %d\n", five);
	printf("$1 bills: %d\n", one);
	return 0;
}

void pay_amount(int dollar, int *twenty, int *ten, int *five, int *one) {
	*twenty = dollar / 20;
	dollar %= 20;
	*ten = dollar / 10;
	dollar %= 10;
	*five = dollar / 5;
	dollar %= 5;
	*one = dollar;
}
