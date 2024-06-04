#include <stdio.h>
#include <stddef.h>

struct s {
	char a; // 3 bytes hole after a
	int b[2];
	float c;
};

int main(void) {
	printf("a: %ld\n", offsetof(struct s, a)); // 0
	printf("b: %ld\n", offsetof(struct s, b)); // 4
	printf("b: %ld\n", offsetof(struct s, b[1])); // 8
	printf("c: %ld\n", offsetof(struct s, c)); // 12

	return 0;
}
