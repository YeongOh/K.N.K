#include <stdio.h>

#define MAX_DIGITS 10

char digits[4][MAX_DIGITS * 4];
const int segments[10][7] = {{1, 1, 1, 1, 1, 1},
                             {0, 1, 1},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
	clear_digits_array();
	printf("Enter a number: ");
	char digit;
	int i = 0;
	do {
		digit = getchar();
		if (digit < '0' || digit > '9') {
			continue;
		}
		process_digit(digit - '0', i);
		i++;
	} while (digit != '\n');
	print_digits_array();

	return 0;
}

void clear_digits_array() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++) {
			digits[i][j] = ' ';
		}
	}
}

void process_digit(int digit, int position) {
	int x = position * 4;
	for (int i = 0; i < 7; i++) {
		if (segments[digit][i] == 0) {
			continue;
		}

		switch (i) {
			case 0: digits[0][x + 1] = '_'; break;
			case 1: digits[1][x + 2] = '|'; break;
			case 2: digits[2][x + 2] = '|'; break;
			case 3: digits[2][x + 1] = '_'; break;
			case 4: digits[2][x]     = '|'; break;
			case 5: digits[1][x]     = '|'; break;
			case 6: digits[1][x + 1] = '_'; break;
		}
	}
}

void print_digits_array(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++) {
			printf("%c", digits[i][j]);	
		}
		printf("\n");
	}
}
