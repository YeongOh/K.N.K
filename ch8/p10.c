#include <stdio.h>
#include <stdlib.h>

#define N 8

int main(void) {
	int hours, minutes;
	int total;

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d:%d", &hours, &minutes);
	total = hours * 60 + minutes;

	int departures[N] = { 8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47,
						 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
	int arrivals[N] = { 10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60,
					    16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};
	int closest_time = departures[0];
	int closest = 0;

	for (int i = 0; i < N; i++) {
		int time = abs(total - departures[i]);
		if (time < closest_time) {
			closest_time = time;
			closest = i;
		}
	}

	printf("Closest departure time is ");
	
	if (departures[closest] >= (12 * 60)) {
		printf("%d:%.2d p.m", (departures[closest] - 12) / 60, departures[closest] % 60);
	} else {
		printf("%d:%.2d a.m", departures[closest] / 60, departures[closest] % 60);
	}

	printf(" arriving at ");	
	if (arrivals[closest] >= (12 * 60)) {
		printf("%d:%.2d p.m", (arrivals[closest] - 12) / 60, arrivals[closest] % 60);
	} else {
		printf("%d:%.2d a.m", arrivals[closest] / 60, arrivals[closest] % 60);
	}
	printf("\n");
	return 0;
}
