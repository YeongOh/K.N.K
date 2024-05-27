#include <stdio.h>

int main(void) {
	int hours, minutes;
	int total;

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d:%d", &hours, &minutes);
	total = hours * 60 + minutes;

	int d1 = 8 * 60;
	int d2 = 9 * 60 + 43;
	int d3 = 11 * 60 + 19;
	int d4 = 12 * 60 + 47;
	int d5 = 14 * 60;
	int d6 = 15 * 60 + 45;
	int d7 = 19 * 60;
	int d8 = 21 * 60 + 45;
	
	if (total < d1) {
		printf("Closest departure time is 8:00 a.m, arriving at 10:16 a.m\n");
	} else if (total < d2) {
		printf("Closest departure time is 9:43 a,m, arriving at 11:52 a.m\n");
	} else if (total < d3) {
		printf("Closest departure time is 11:19 a.m, arriving at 1:31 p.m\n");
	} else if (total < d4) {
		printf("Closest departure time is 12:47 p.m, arriving at 3:00 p.m\n");
	} else if (total < d5) {
		printf("Closest departure time is 2:00 p.m, arriving at 4:08 p.m\n");
	} else if (total < d6) {
		printf("Closest departure time is 3:45 p.m, arriving at 5:55 p.m\n");
	} else if (total < d7) {
		printf("Closest departure time is 7:00 p.m, arriving at 9:20 p.m\n");
	} else if (total < d8) {
		printf("Closest departure time is 9:45 p.m, arriving at 11:58 p.m\n");
	} else {
		printf("You have no available flights\n");
	}
	return 0;
}
