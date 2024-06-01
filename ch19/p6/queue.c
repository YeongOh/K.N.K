#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct queue_type {
	Item *contents;
	int first_i;
	int last_i;
	int size;
};

static void terminate(char *message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(int n) {
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL) {
		terminate("Not enough memory\n");
	}
	q->contents = malloc(sizeof(Item) * n);
	if (q->contents == NULL) {
		terminate("Not enough memory\n");
	}
	q->first_i = 0;
	q->last_i = 0;
	q->size = n;
	return q;
}

void push(Queue q, Item i) {
	q->contents[q->last_i] = i;
	q->last_i = (q->last_i + 1) % q->size;
}

Item pop(Queue q) {
	if (is_empty(q)) {
		terminate("empty queue\n");
	}
	Item res = q->contents[q->first_i];
	q->first_i = (q->first_i + 1) % q->size;
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
	free(q->contents);
	free(q);
}
