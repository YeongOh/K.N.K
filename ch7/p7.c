#include <stdio.h>

int main(void)
{
	int num1, denom1, num2, denom2;
	char operation;
	double result_num;

	printf("Enter two fractions separated by a operation sign: ");
	scanf("%d/%d%c%d/%d", &num1, &denom1, &operation, &num2, &denom2);
	
	switch (operation) {
		case '+': result_num = num1 / denom1 + num2 / denom2; break;
		case '-': result_num = num1 / denom1 - num2 / denom2; break;
		case '*': result_num = num1 / denom1 * num2 / denom2; break;
		case '/': result_num = num1 / denom1 / num2 / denom2; break;
		default: break;
	}
	printf("The result is %f\n", result_num);

	return 0;
}
