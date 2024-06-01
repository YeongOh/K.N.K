#include <stdio.h>

int main(void) {
	const char *tens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
						  "sixteen", "seventeen", "eighteen", "ninenteen"};
	const char *double_digit[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy",
								"eighty", "ninety"};
	const char *digit[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int n;
	printf("Enter a two-digit number: ");
	scanf("%d", &n);
	
	if (n < 10 || n > 99) {
		printf("Your number is not in range of 10 and 99\n");
		return 0;
	}

	printf("You entered the number ");

	if (n >= 10 && n <= 19) {
		printf("%s", tens[n - 10]);
	} else if (n >= 20) {
		if (n % 10 == 0) {
			printf("%s", double_digit[(n / 10) - 2]);
		} else {
			printf("%s-%s", double_digit[(n / 10) - 2], digit[n % 10 - 1]);
		}
	}
	printf("\n");

	return 0;
}
