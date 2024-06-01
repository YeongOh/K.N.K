#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void push(char p);
char pop(void);
bool is_empty(void);

int main(void) {
	printf("Enter parentheses and/or braces: ");
	char ch;
	while ((ch = getchar()) != '\n') {
		push(ch);
	}
	if (is_empty()) {
		printf("Parentheses/braces are nested properly.\n");
	} else {
		printf("Parentheses/braces are not nested properly.\n");
	}	
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
		if (p == ')') {
			char p = pop();
			if (p != '(') 
				push(p);
		} else if (p == '}') {
			char p = pop();
			if (p != '{')
				push(p);
		} else {
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
