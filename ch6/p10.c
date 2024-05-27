#include <stdio.h>

int main(void) {

	int year = 0, month = 0, date = 0;

	while (1) {
		int year2, month2, date2;
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d", &month2, &date2, &year2);
		
		if (year == 0) {
			year = year2, month = month2, date = date2;
			continue;
		}
		if (year2 == 0 && month2 == 0 && date2 == 0) {
			break;
		}
		if (year > year2) {
			year = year2, month = month2, date = date2;
			continue;
		}
		if (year == year2 && month > month2) {
			year = year2, month = month2, date = date2;
			continue;
		}
		if (year == year2 && month > month2 && date > date2) {
			year = year2, month = month2, date = date2;
			continue;
		}
 	}

	printf("%d/%d/%.2d is the earliest date\n", month, date, year);

	return 0;
}
