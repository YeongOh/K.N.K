#include <stdio.h>

#define N 25

void selection_sort(int arr[], int size);

int main(void) {
	int arr[N];
	printf("This program will sort an array with maximum of 25 elements\n");
	printf("Enter a series of integers to sort (0 to stop) :");

	int i;
	for (i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		if (input == 0) {
			break;
		}
		arr[i] = input;
	}

	selection_sort(arr, i);

	printf("Sorted Array : ");	
	for (int j = 0; j < i; j++) {
		printf("%3d", arr[j]);
	}
	printf("\n");

	return 0;
}

void selection_sort(int arr[], int size) {
	if (size == 1) {
		return;
	}

	int largest = arr[0];
	int largest_index = 0;

	for (int i = 1; i < size; i++) {
		if (largest < arr[i]) {
			largest = arr[i];
			largest_index = i;
		}
	}

	int temp = arr[size - 1];
	arr[size - 1] = largest;
	arr[largest_index] = temp;

	selection_sort(arr, size - 1);
}
