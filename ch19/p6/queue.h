#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create(int n);
void push(Queue q, Item i);
Item pop(Queue q);
Item first(Queue q);
Item last(Queue q);
bool is_empty(Queue q);
void destroy(Queue q);

#endif
