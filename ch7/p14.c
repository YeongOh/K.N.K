#include <stdio.h>
#include <math.h>

int main(void) {
	double x, y, average;
	printf("Enter a positive number: ");
	scanf("%lf", &x);

	y = 1;
	
	while(1) {
		double divided = x / y;
		average = (y + divided) / 2;

		if (fabs(average - y) < y * 0.00001) {
			break;
		}
		y = average;
	}
	printf("Square root %.5f\n", y);

	return 0;
}
