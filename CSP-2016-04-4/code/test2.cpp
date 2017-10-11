#include <stdio.h>
#include <queue>
using namespace std;
typedef struct _Node
{
	int row;			
	int col;			
	int step;			
}Node, Det ;

typedef struct _Map
{
	int startTime;	
	int endTime  ;	
}Map;

Map map[105][105];

queue<Node> q;	
 
bool flag[101][101][101] = {0};

int main()
{
	
	int i, j; 
		
	int m, n, t; 
	int r, c, a, b;
	scanf("%d%d%d",&n,&m,&t);
		
	for( i = 1; i <= n; i++)
		for( j = 1; j <= m; j++)
			map[i][j].startTime = map[i][j].endTime= 0;	

	for( i = 1; i <= t; i++)
	{
		scanf("%d%d%d%d", &r, &c, &a, &b );
		map[r][c].startTime = a;
		map[r][c].endTime   = b;
	}

	int judge;
	
	Node temp, nextNode;
	temp.row  = temp.col = 1;
	temp.step = 0;	

	q.push(temp);

	Det det[4] = { {0,1,0},{1,0,0},{0,-1,0},{-1,0,0} };		
	
	int newRow,newCol;
	
	while( q.empty() == 0 )
	{
		temp = q.front();
		q.pop();
		if( temp.row == n && temp.col == m )
		{		
			printf("%d",temp.step);	
			break;
		}
		nextNode.step = temp.step + 1;
		for( i = 0; i < 4; i++ )
		{
			newRow = temp.row + det[i].row;
			newCol = temp.col + det[i].col;				
			if( 
				newRow >= 1 && newRow <= n &&
				newCol >= 1 && newCol <= m &&
				( nextNode.step < map[ newRow  ][ newCol ].startTime ||
				  nextNode.step > map[ newRow  ][ newCol ].endTime  )&&
				 flag[ newRow ][ newCol ][ nextNode.step ] == 0
			  )
			{
				nextNode.row = newRow;
				nextNode.col = newCol;
				
				flag[newRow][newCol][nextNode.step] = 1;	
				q.push(nextNode);
			}
			else
				judge ++;
		}
	}	
	
	return 0;
}
 
