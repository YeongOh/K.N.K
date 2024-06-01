#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

void my_push(char p, Stack s1);

int main(void) {
	Stack s1;
	s1 = create();

	printf("Enter an RPN expression: ");
	char in;
	do {
		scanf(" %c", &in);
		my_push(in, s1);
	} while (in != '=');

	char result = pop(s1);
	printf("Value of expression: %c\n", result);
}

void my_push(char p, Stack s)
{
	if (p == '=') {
		return;
	}

	if (p == '+' || p == '-' || p == '*' || p == '/') {
		int b = pop(s) - '0';
		int a = pop(s) - '0';
		char res;
		switch (p) {
			case '+' : res = a + b; break;
			case '-' : res = a - b; break;
			case '*' : res = a * b; break;
			case '/' : res = a / b; break;
		}	
		push(s, res + '0');
		return;
	}

	if (p >= '0' && p <= '9') {
		push(s, p);
	}
}

