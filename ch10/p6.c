#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void push(char p);
char pop(void);
bool is_empty(void);
void make_empty(void);

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


void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void) 
{
	return top == STACK_SIZE;
}

void stack_overflow(void) {
	printf("stack overflow\n");
	exit(EXIT_FAILURE);	
}

void stack_underflow(void) {
	printf("stack underflow\n");
}

void push(char p)
{
	if (is_full())
		stack_overflow();
	else {
		if (p == '=') {
			return;
		}

		if (p == '+' || p == '-' || p == '*' || p == '/') {
			int b = pop() - '0';
			int a = pop() - '0';
			char res;
			switch (p) {
				case '+' : res = a + b; break;
				case '-' : res = a - b; break;
				case '*' : res = a * b; break;
				case '/' : res = a / b; break;
			}	
			contents[top++] = res + '0';
			return;
		}
		if (p >= '0' && p <= '9') {
			contents[top++] = p;	
		}
	}
}

char pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}
