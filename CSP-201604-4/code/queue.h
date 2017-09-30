#ifndef _QUEUE_H
#define _QUEUE_H


#define TRUE	1
#define FALSE	0

typedef char BOOLEAN;

typedef struct _Node
{
	int row;			//行
	int col;			//列
	int step;			//时间
}Node, Det ;

typedef struct _Queue Queue;

void initQueue(Queue *queue);

struct _Queue
{
	int head;
	int rear;
	Node element[10001];
	void 	(* push_back	)(Queue *queue, Node node);
	void	(* pop_head	)(Queue *queue);
	BOOLEAN (* emptyQueue	)(Queue *queue);
	Node	(* get_head	)(Queue *queue);
};




#endif
