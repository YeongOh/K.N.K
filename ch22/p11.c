#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int month, day, year;
	const char *month_string[] = { "", "January", "February", "March", "April", "May", "June",
									   "July", "August", "September", "October", "November", "December"};
	
	if (argc != 2) {
		fprintf(stderr, "usage: date datestring(mm-dd-yyyy)\n");
		exit(EXIT_FAILURE);
	}

	sscanf(argv[1], "%d%*[-/]%d%*[-/]%d", &month, &day, &year);
	printf("%s %d, %d\n", month_string[month], day, year);

	return 0;
}
