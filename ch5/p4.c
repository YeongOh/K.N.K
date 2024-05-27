#include <stdio.h>

int main(void) {
	int wind_speed;
	printf("Enter the wind speed in knots: ");
	scanf("%d", &wind_speed);

	if (wind_speed < 1) {
		printf("The wind is calm\n.");
	} else if (wind_speed <= 3) {
		printf("The wind is light air\n.");
	} else if (wind_speed <= 27) {
		printf("The wind is breeze\n.");
	} else if (wind_speed <= 47) {
		printf("The wind is gale\n.");
	} else if (wind_speed <= 63) {
		printf("The wind is storm\n.");
	} else {
		printf("The wind is hurricane\n.");
	}

	return 0;
}
