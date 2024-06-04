#include <stdio.h>

union f {
	float number;
	struct {
		unsigned int fraction: 23;
		unsigned int exponential: 8;
		unsigned int sign: 1;
	} IEEE;
};

int main(void) {
	union f n;
	n.IEEE.sign = 1;
	n.IEEE.exponential = 128;
	n.IEEE.fraction = 0;

	printf("%.1f\n", n.number);
	return 0;
}
