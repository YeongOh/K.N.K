#include <stdio.h>

int main(void)
{
	int gs1, group_id, publisher_code, item_number, check_digit;
	
	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d-%d", &gs1, &group_id, &publisher_code, &item_number, &check_digit);

	printf("GS1 prefix: %d\n", gs1);
	printf("Group identifier: %d\n", group_id);
	printf("Publisher code: %d\n", publisher_code);
	printf("item_number: %d\n", item_number);
	printf("check_digit: %d\n", check_digit);
	return 0;
}

