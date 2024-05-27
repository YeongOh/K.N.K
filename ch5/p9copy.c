#include <stdio.h>

int main(void) {
	int year, month, date;
	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &month, &date, &year);

	int year2, month2, date2;
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &month2, &date2, &year2);
 
	if (year < year2) {
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
				month, date, year, month2, date2, year2);
	} else if (year > year2) {
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
				month2, date2, year2, month, date, year);
	} else {
		if (month < month2) {
			printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
					month, date, year, month2, date2, year2);
		} else if (month > month2) {
			printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
					month2, date2, year2, month, date, year);
		} else {
			if (date < date2) {
				printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
						month, date, year, month2, date2, year2);
			} else if (date > date2) {
				printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
						month2, date2, year2, month, date, year);
			} else {
				printf("They are the same date\n");
			}
		}
	}

	return 0;
}
