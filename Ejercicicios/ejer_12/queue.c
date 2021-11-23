#include <stdlib.h>
#include "queue.h"

queue* create() {
	queue* new_queue = malloc(sizeof(queue));
	new_queue->first = NULL;
	new_queue->last = NULL;
	return new_queue;
}

int is_empty(queue* q) {
	return q->first == NULL;
}

void add(queue* q, int number) {
	if ( is_empty(q) )
	{
		q->first = malloc(sizeof(node_t));
		q->first->data[0] = number;
		q->first->len = 1;
		q->first->next = NULL;
		q->last = q->first;
	}
	else if ( q->last->len < DATA_SIZE )
	{
		q->last->data[q->last->len] = number;
		++(q->last->len);
	}
	else
	{
		node_t *nn = malloc(sizeof(node_t));
		nn->data[0] = number;
		nn->len = 1;
		nn->next = NULL;
		q->last->next = nn;
		q->last = nn;
	}
}

