#include <stdio.h>

int main(void) {
	double result = 0;
	printf("Enter an expression: ");
	scanf("%lf", &result);

	char operator;
	double operand;
	while ((operator = getchar()) != '\n') {
		scanf("%lf", &operand);

		switch (operator) {
			case '+': result += operand; break;
			case '-': result -= operand; break;
			case '*': result *= operand; break;
			case '/': result /= operand; break;
			default: break;
		}
	}
	printf("Value of expression: %.2f\n", result);

	return 0;
}
