#include <stdio.h>

int main(void) {
	printf("sizeofint: %d \n", (int)sizeof(int));
	printf("sizeofshort: %d \n", (int)sizeof(short));
	printf("sizeoflong: %d \n", (int)sizeof(long));
	printf("sizeoffloat: %d \n", (int)sizeof(float));
	printf("sizeofdouble: %d \n", (int)sizeof(double));
	printf("sizeoflongdouble: %d \n", (int)sizeof(long double));


	return 0;
}
