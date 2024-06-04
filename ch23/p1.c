#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	double a, b, c, x1, x2, root;
	printf("Enter value for a: ");
	scanf("%lf", &a);

	printf("Enter value for b: ");
	scanf("%lf", &b);

	printf("Enter value for c: ");
	scanf("%lf", &c);

	root = pow(b, 2.0) - (4 * a * c);
	if (isless(root,  0.0)) {
		fprintf(stderr, "root negative\n");
		exit(EXIT_FAILURE);
	}

	x1 = (-b + sqrt(root)) / 2 * a;
	x2 = (-b - sqrt(root)) / 2 * a;
	
	printf("x is %g or %g\n", x1, x2);

	return 0;
}
