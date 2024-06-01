#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void) {
	Stack s;
	s = create();

	printf("Enter parentheses and/or braces: ");
	char ch;
	bool isProper = true;
	while ((ch = getchar()) != '\n') {
		if (ch == '}') {
			if (pop(s) == '{') {
				continue;
			} else {
				isProper = false;
			}
		} else if (ch == ')') {
			if (pop(s) == '(') {
				continue;
			} else {
				isProper = false;
			}
		} else {
			push(s, ch);
		}
	}

	if (is_empty(s) && isProper == true) {
		printf("Parentheses/braces are nested properly.\n");
	} else {
		printf("Parentheses/braces are not nested properly.\n");
	}
}
