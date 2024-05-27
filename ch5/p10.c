#include <stdio.h>

int main(void) {
	int grade;
	printf("Enter numeric grade: ");
	scanf("%d", &grade); 
 
	if (grade > 100 || grade < 0) {
		printf("Grade must be within a range of 0 and 100\n");
		return 0;
	}

	switch (grade / 10) {
		case 10: 
		case 9: printf("Letter Grade: A\n");
				break;
		case 8: printf("Letter Grade: B\n");
				break;
		case 7: printf("Letter Grade: C\n");
				break;
		case 6: printf("Letter Grade: D\n");
				break;
		case 5: printf("Letter Grade: E\n");
				break;
		case 4:
		case 3:
		case 2:
		case 1:
		case 0: printf("Letter Grade: F\n");
				break;
	}

	return 0;
}
