#include <stdio.h>

int main(void) {
	int hours;
	int minutes;

	printf("Enter a 24-hour time (hh:mm) : ");
	scanf("%d:%d", &hours, &minutes);

	if (hours <= 12) {
		printf("Equivalent 12-hour time: %.2d:%.2d AM\n", hours, minutes);
	} else {
		printf("Equivalent 12-hour time: %.2d:%.2d PM\n", hours - 12, minutes);
	}

	return 0;
}
