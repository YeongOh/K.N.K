#include <stdio.h>

int main(void) {
	int n;
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic squares: ");
	scanf("%d", &n);
	int a[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}

	int x = n / 2;
	int y = 0;
	for (int i = 1; i <= n * n; i++) {
		a[y][x] = i;
		
		int newY = y - 1 < 0 ? n - 1 : y - 1;
		int newX = (x + 1) % n;
		
		if (a[newY][newX] == 0) {
			y = newY;
			x = newX;
		} else {
			y = y + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
