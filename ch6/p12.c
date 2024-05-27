#include <stdio.h>

int main(void) {
	float n = 0;
	printf("Enter n to compute e: ");
	scanf("%f", &n);

	float sum = 1.0f;
	int deno = 1;
	int i = 1;
	while (1) {
		deno *= i;
		float current_term = 1.0f / deno;
		if (current_term < n) {
			break;
		}
		sum += 1.0f / deno;
		i++;
	}
	
	printf("The value of e is: %.3f\n", sum);

	return 0;
}
