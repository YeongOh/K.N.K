#include <stdio.h>

int main(void) {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	int i = 2;
	while (i * i <= n) {
		printf("%d\n", i * i);
		i += 2;
	}

	return 0;
}
