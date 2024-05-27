#include <stdio.h>

int main(void)
{
	int radius;
	printf("Enter the radius of the sphere: ");
	scanf("%d", &radius);
	int volume = 4.0f / 3.0f * 3.14 * radius * radius * radius;
	printf("The volume of the sphere is %d\n", volume);
	return 0;
}
