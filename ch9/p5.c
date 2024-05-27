#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void) {
	int n;
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic squares: ");

	scanf("%d", &n);
	int a[n][n];
	create_magic_square(n, a);	

	print_magic_square(n, a);

	return 0;
}

void create_magic_square(int n, int magic_square[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			magic_square[i][j] = 0;
		}
	}

	int x = n / 2;
	int y = 0;
	for (int i = 1; i <= n * n; i++) {
		magic_square[y][x] = i;
		
		int newY = y - 1 < 0 ? n - 1 : y - 1;
		int newX = (x + 1) % n;
		
		if (magic_square[newY][newX] == 0) {
			y = newY;
			x = newX;
		} else {
			y = y + 1;
		}
	}
}

void print_magic_square(int n, int magic_square[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", magic_square[i][j]); 
		}
		printf("\n");
	}
}
