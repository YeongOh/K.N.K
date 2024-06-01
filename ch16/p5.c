#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int departure_time;
	int arrival_time;
} flight;

int main(void) {
	flight times[8] = {
		{8 * 60, 10 * 60 + 16},
		{9 * 60 + 43, 11 * 60 + 52},
		{11 * 60 + 19, 13 * 60 + 31},
		{12 * 60 + 47, 15 * 60},
		{14 * 60, 16 * 60 + 8},
		{15 * 60 + 45, 17 * 60 + 55},
		{19 * 60, 21 * 60 + 20},
		{21 * 60 + 45, 23 * 60 + 58}
	};

	int hours, minutes;
	int total;

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d:%d", &hours, &minutes);
	total = hours * 60 + minutes;
	printf("total: %d\n", total);

	int closest_time = abs(times[0].departure_time - total);
	int closest_index = 0;
	for (int i = 1; i < 8; i++) {
		if (closest_time > abs(times[i].departure_time - total)) {
			closest_time = abs(times[i].departure_time - total);
			closest_index = i;
		}
	}
	int departure = times[closest_index].departure_time;
	int arrival = times[closest_index].arrival_time;

	printf("The closest departure time is: %d, arrival time: %d\n", departure, arrival);
	
	
	return 0;
}
