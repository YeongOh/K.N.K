#include <stdio.h>

int main(void) {
	int input[5][5] = {0};

	for (int i = 0; i < 5; i++) {
		printf("Enter row %d: ", i);
		for (int j = 0; j < 5; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	printf("Row totals: ");
	for (int i = 0; i < 5; i++) {
		int total = 0;
		for (int j = 0; j < 5; j++) {
			total += input[i][j];
		}
		printf("%3d", total);
	}
	printf("\n");
	
	printf("Column totals: ");
	for (int i = 0; i < 5; i++) {
		int total = 0;
		for (int j = 0; j < 5; j++) {
			total += input[j][i];
		}
		printf("%3d", total);
	}
	printf("\n");

	return 0;
}
