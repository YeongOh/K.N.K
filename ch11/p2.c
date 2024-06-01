#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void find_closest_flight(int desired_time,
						 int *departure_time,
						 int *arrival_time);

int main(void) {
	int hours, minutes;
	
	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d:%d", &hours, &minutes);

	int desired_time = hours * 60 + minutes;
	int departure_time, arrival_time;

	find_closest_flight(desired_time, &departure_time, &arrival_time);

	int departure_hours = departure_time / 60;
	int departure_minutes = departure_time % 60;
	int arrival_hours = arrival_time / 60;
	int arrival_minutes = arrival_time % 60;

	printf("Closest departure time is ");
	if (departure_hours >= 12) {
		printf("%d:%.2d p.m,", departure_hours == 12 ? 12 : departure_hours - 12, departure_minutes); 
	} else {
		printf("%d:%.2d a.m,", departure_hours, departure_minutes); 
	}

	if (arrival_hours >= 12) {
		printf(" arriving at %d:%.2d p.m.\n", arrival_hours == 12 ? 12 : arrival_hours - 12, arrival_minutes); 
	} else {
		printf(" arriving at %d:%.2d a.m.\n", arrival_hours, arrival_minutes); 
	}

	return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
	int closest_time_diff = INT_MAX;
	int closest_index = -1;
	
	const int departures[8] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47,
							   14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
	const int arrivals[8] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60,
							 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};
	for (int i = 0; i < 8; i++) {
		int time_diff = abs(departures[i] - desired_time); 
		if (time_diff < closest_time_diff) {
			closest_time_diff = time_diff;
			closest_index = i;
		}
	}

	*departure_time = departures[closest_index];
	*arrival_time = arrivals[closest_index];
}
