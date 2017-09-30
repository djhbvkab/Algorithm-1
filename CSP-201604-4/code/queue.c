#include "queue.h"

BOOLEAN emptyQueue(Queue *queue)
{
	return queue->head == queue->rear;
}

void push_back(Queue *queue, Node node)
{
	queue->element[ queue->rear++ ] = node;
}

void pop_head(Queue *queue)
{
	queue->head ++;
}

Node get_head(Queue *queue)
{
	return queue->element[queue->head];
}

void initQueue(Queue *queue)
{
	queue->head = queue->rear = 0;
	queue->push_back  = push_back;
	queue->pop_head	  = pop_head;
	queue->get_head   = get_head;
	queue->emptyQueue = emptyQueue;
}
