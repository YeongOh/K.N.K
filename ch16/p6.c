#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

int day_of_year(const struct date d);
int compare_dates(const struct date d1, const struct date d2);

int main(void) {
	struct date d1, d2;
	printf("Enter first date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

	printf("Enter second date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);
 
	int result = compare_dates(d1, d2);
	if (result == -1) {
		printf("The first date is earlier than the second date\n");
	} else if (result == 1) {
		printf("The second date is earlier than the first date\n");
	} else {
		printf("The dates are the same\n");
	}

	return 0;
}

int day_of_year(const struct date d) {
	return d.month * 30 + d.day;
}
int compare_dates(const struct date d1, const struct date d2) {
	int d1total = d1.year * 365 + day_of_year(d1);
	int d2total = d2.year * 365 + day_of_year(d2);
	if (d1total < d2total)
		return -1;
	else if (d1total > d2total)
		return 1;
	return 0;
}

