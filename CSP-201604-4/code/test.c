//main.c 算法部分的实现
#include <stdio.h>
#include <stdlib.h>


//#define TEST

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
};


typedef struct _Map
{
	int startTime;	//危险起始时刻
	int endTime  ;	//危险终止时刻
}Map;

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
}


int main()
{
	Map map[101][101];

	Queue queue;		
	int m, n, t; //n===行 m====列
	int r, c, a, b;
	scanf("%d%d%d",&n,&m,&t);
		
	initQueue(&queue);	//初始化队列
	if( m < 1 || n < 1 || t < 0)
		exit(0);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			map[i][j].startTime = map[i][j].endTime= -1;	
	for(int i = 1; i <= t; i++)
	{
		scanf("%d%d%d%d", &r, &c, &a, &b );
		map[r][c].startTime = a;
		map[r][c].endTime   = b;
	}
	
	Node temp, nextNode;
	temp.row = temp.col = 1;
	temp.step = 0;	

	push_back(&queue, temp);

	Det det[4] = { {0,1,0},{1,0,0},{0,-1,0},{-1,0,0} };		
	

	
	while( !emptyQueue(&queue) )
	{
		temp = get_head(&queue);		
		for( int i = 0; i < 4; i++ )
		{
						
			if( 
				temp.row + det[i].row >= 1 && temp.row + det[i].row <= n &&
				temp.col + det[i].col >= 1 && temp.col + det[i].col <= m &&
				( temp.step+1 < map[ temp.row + det[i].row  ][ temp.col + det[i].col].startTime ||
				temp.step+1 > map[ temp.row + det[i].row  ][ temp.col + det[i].col].endTime  )
			  )
			{
				nextNode.row = temp.row + det[i].row;
				nextNode.col = temp.col + det[i].col;
				nextNode.step = temp.step + 1;
				push_back(&queue,nextNode);

			}

		}
		if( temp.row == m && temp.col == n )
		{
			printf("%d\n",temp.step);			
			break;
		}
		pop_head(&queue);
	}	
	
	return 0;
}
