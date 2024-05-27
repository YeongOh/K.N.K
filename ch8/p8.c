#include <stdio.h>

int main(void) {
	int input[5][5] = {0};

	for (int i = 0; i < 5; i++) {
		printf("Enter 5 scores(0-100) for student %d: ", i + 1);
		for (int j = 0; j < 5; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("Student %d - ", i + 1);
		int total = 0;
		for (int j = 0; j < 5; j++) {
			total += input[i][j];
		}
		printf("total : %d, average : %.1f\n", total, total / 5.0);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("Quiz %d - ", i + 1);
		int total = 0;
		int low = 100;
		int high = 0;
		for (int j = 0; j < 5; j++) {
			total += input[j][i];
			if (input[j][i] < low) {
				low = input[j][i];
			}
			if (input[j][i] > high) {
				high = input[j][i];
			}
		}
		printf("average : %.1f, high : %d, low : %d\n", total / 5.0, high, low);
	}
	printf("\n");
	return 0;
}
