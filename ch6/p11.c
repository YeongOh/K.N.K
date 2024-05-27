#include <stdio.h>

int main(void) {
	int n = 0;
	printf("Enter n to compute e: ");
	scanf("%d", &n);

	float sum = 1.0f;
	int deno = 1;
	for (int i = 1; i <= n; i++) {
		deno *= i;
		sum += 1.0f / deno;
	}
	
	printf("The value of e is: %.3f\n", sum);

	return 0;
}
