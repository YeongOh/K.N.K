#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void push(char p);
char pop(void);
bool is_empty(void);
void make_empty(void);
int evaluate_RPN_expression(const char *expression);
int read_line(char *str, int n);

int main(void) {
	printf("Enter an RPN expression: ");
	char expression[STACK_SIZE];
	read_line(expression, STACK_SIZE);

	printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
	make_empty();
}

int read_line(char *str, int n) {
	int i = 0;
	char ch;
	while ((ch = getchar()) != '=') {
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = 0;
	return i;
}

int evaluate_RPN_expression(const char *expression) {
	while (*expression) {
		if (isspace(*expression)) {
			expression++;
			continue;
		}
		push(*expression);
		expression++;
	}
	char result[] = {pop(), '\0'};
	return atoi(result);
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
