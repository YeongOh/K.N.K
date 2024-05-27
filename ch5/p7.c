#include <stdio.h>

int main(void) {
	int d1, d2, d3, d4;
	
	printf("Enter four integers:");
	scanf("%d%d%d%d", &d1, &d2, &d3, &d4);

	int largest = d1;
	int smallest = d1;

	if (largest < d2) {
		largest = d2;
	} else if (largest < d3) {
		largest = d3;
	} else if (largest < d4) {
		largest = d4;
	}

	if (smallest > d2) {
		smallest = d2;
	} else if (smallest > d3) {
		smallest = d3;
	} else if (smallest > d4) {
		smallest = d4;
	}

	printf("Largest: %d\n", largest);
	printf("Smallest: %d\n", smallest);
	 
	return 0;
}
