#include <stdio.h>
#include <ctype.h>

int main(void) {
	int hours;
	int minutes;
	char indicator;
	printf("Enter a 12-hour time (hh/mm PM) : ");
	scanf("%d:%d", &hours, &minutes);

	while ((indicator = getchar()) != '\n') {
		if (toupper(indicator) == 'P') {
			hours += 12;
			break;
		}
		if (toupper(indicator) == 'A') {
			break;
		}
	}
	

	printf("Equivalent 24-hour time: %d:%d\n", hours, minutes);

	return 0;
}
