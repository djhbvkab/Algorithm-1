//main.c 算法部分的实现
#include <stdio.h>
#include "queue.h"
#include <stdlib.h>


//#define TEST

typedef struct _Map
{
	int startTime;	//危险起始时刻
	int endTime  ;	//危险终止时刻
}Map;



int main(int argc,char* argv[])
{
	Map map[101][101];

	Queue queue;		
	int m, n, t; //n===行 m====列
	int r, c, a, b;
	scanf("%d%d%d",&n,&m,&t);
	
	#ifdef TEST
		printf("n = %d m = %d t = %d\n",n,m,t);
	#endif	
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
		#ifdef TEST
			printf("r = %d c = %d a = %d b = %d\n", r, c, a, b);		
		#endif
	}
	
	Node temp, nextNode;
	temp.row = temp.col = 1;
	temp.step = 0;	

	queue.push_back(&queue, temp);

	Det det[4] = { {0,1,0},{1,0,0},{0,-1,0},{-1,0,0} };		
	

	
	while( !queue.emptyQueue(&queue) )
	{
		temp = queue.get_head(&queue);
		#ifdef TEST
			printf("head_row = %d head_col = %d head_step = %d\n",temp.row, temp.col, temp.step);		
		#endif		
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
				queue.push_back(&queue,nextNode);

				#ifdef TEST
					printf("row = %d col = %d step = %d\n",nextNode.row, nextNode.col, nextNode.step);		
				#endif	
			}

		}
		if( temp.row == m && temp.col == n )
		{
			printf("%d\n",temp.step);			
			break;
		}
		queue.pop_head(&queue);
	}	
	
	return 0;
}
