#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const char *months[] = {"January", "February", "March", "April",
							"May", "June", "July", "August", "September",
							"October", "November", "December"};
	char month[3], day[3], year[5];
	printf("Enter a date (mm/dd/yyyy): ");

	char ch;
	int i = 0, j = 0, k = 0;
	while ((ch = getchar()) != '/') 
		month[i++] = ch;
	month[i] = 0;

	while ((ch = getchar()) != '/')
		day[j++] = ch;
	day[j] = 0;
	
	while ((ch = getchar()) != '\n') 
		year[k++] = ch;
	year[k] = 0;

	int month_index = atoi(month) - 1;
	printf("You entered the date %s %s, %s\n", months[month_index], day, year); 

	return 0;
}
