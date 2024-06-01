#include <stdio.h>
#include "stack.h"

int main(void) {
	printf("Enter an RPN expression: ");
	char in;
	do {
		scanf(" %c", &in);
		push(in);
	} while (in != '=');
	char result = pop();
	printf("Value of expression: %c\n", pop());
	make_empty();
}
