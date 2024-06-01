#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

void push(char p);
char pop(void);
bool is_empty(void);
void make_empty(void);

#endif
