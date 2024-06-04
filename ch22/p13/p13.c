#include <stdio.h>
#include <stdlib.h>

#define N 100

struct flight {
	int departure;
	int arrival;
};

int main(void) {
	int i, j, hours, minutes, total;
	int d_hours, d_minutes, a_hours, a_minutes;
	int closest_total, closest_index;
	struct flight info[N];
	unsigned char buff[BUFSIZ];
	FILE *fp;

	if ((fp = fopen("flights.dat", "r")) == NULL) {
		fprintf(stderr, "Missing flights.dat file.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d:%d", &hours, &minutes);
	total = hours * 60 + minutes;

	i = 0;	
	while (fgets(buff, BUFSIZ - 1, fp) != NULL) {
		sscanf(buff, "%d:%d %d:%d", &d_hours, &d_minutes, &a_hours, &a_minutes); 
		info[i].departure = d_hours * 60 + d_minutes;
		info[i].arrival = a_hours * 60 + d_minutes;
		i++;
	}

	closest_total = abs(info[0].departure - total);
	closest_index = 0;
	for (j = 1; j < i; j++) {
		if (abs(total - info[j].departure) < closest_total) {
			closest_total = abs(total - info[j].departure);
			closest_index = j;
		}
	}

	printf("Closeset departure is %d, arriving at %d\n", info[closest_index].departure, info[closest_index].arrival);

	return 0;
}
