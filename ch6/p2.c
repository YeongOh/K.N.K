#include <stdio.h>

int main(void) {
	int m, n;
	printf("Enter two integers: ");
	scanf("%d%d", &m, &n);

	if (m < n) {
		int temp = m;
		m = n;
		n = temp;
	}

	while (n != 0) {
		int remainder = m % n;
		m = n;
		n = remainder;
	}

	printf("Greatest common divisor: %d\n", m);

	return 0;
}

