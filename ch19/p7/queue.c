#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
	Item data;
	struct node *next;
};

struct queue_type {
	struct node *first_i;
	struct node *last_i;
	int size;
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
	q->first_i = NULL;
	q->last_i = NULL;
	return q;
}

void push(Queue q, Item i) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->data = i;
	new_node->next = NULL;
	if (new_node == NULL) {
		terminate("new node push fail\n");
	}
	if (q->first_i == NULL) {
		q->first_i = new_node;
		q->last_i = new_node;
	} else {
		q->last_i->next = new_node;
		q->last_i = new_node;
	}
}

Item pop(Queue q) {
	if (is_empty(q)) {
		terminate("empty queue\n");
	}
	Item res = q->first_i->data;
	struct node *old = q->first_i;
	q->first_i = q->first_i->next;
	free(old);
	return res;
}

Item first(Queue q) {
	return q->first_i->data;
}

Item last(Queue q) {
	return q->last_i->data;
}

bool is_empty(Queue q) {
	return q->first_i == NULL;
}

void destroy(Queue q) {
	while (q->first_i) {
		struct node *temp = q->first_i;
		q->first_i = q->first_i->next;
		free(temp);
	}
	free(q);
}
