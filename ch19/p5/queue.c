#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

struct queue_type {
	int contents[QUEUE_SIZE];
	int first_i;
	int last_i;
};

static void terminate(char *message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void) {
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL) {
		terminate("Not enough memory\n");
	}
	q->first_i = 0;
	q->last_i = 0;
	return q;
}

void push(Queue q, Item i) {
	q->contents[q->last_i] = i;
	q->last_i = (q->last_i + 1) % QUEUE_SIZE;
}

Item pop(Queue q) {
	if (is_empty(q)) {
		terminate("empty queue\n");
	}
	Item res = q->contents[q->first_i];
	q->first_i = (q->first_i + 1) % QUEUE_SIZE;
	return res;
}

Item first(Queue q) {
	return q->contents[q->first_i];
}

Item last(Queue q) {
	return q->contents[q->last_i];
}

bool is_empty(Queue q) {
	return q->first_i == q->last_i;
}

void destroy(Queue q) {
	free(q);
}
