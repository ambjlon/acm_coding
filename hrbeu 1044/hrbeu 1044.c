#include <stdio.h>
#include <math.h>

typedef struct node
{
	int x,y;
}Node,*PNode;

double graph[202][202];
int main()
{
	int i,j;
	int n,k;
	int counter;
	double mark[202];
	Node tmp[202];

	counter = 1;
	scanf("%d",&n);
	while(n != 0)
	{
		for(i = 0;i < n; i ++)
			scanf("%d%d",&tmp[i].x,&tmp[i].y);
	    for(i = 0;i < n;i ++)
			graph[i][i] = 0;
    	for(i = 0;i < n;i ++)
			for(j = 0;j < i;j ++)
				graph[i][j] = graph[j][i] = sqrt((tmp[i].x - tmp[j].x) * (tmp[i].x - tmp[j].x) + (tmp[i].y - tmp[j].y) * (tmp[i].y - tmp[j].y));
	    for(i = 1;i < n;i ++)
			mark[i] = graph[0][i];
		while(1)
		{
			for(i = 1;i < n;i ++)
				if(mark[i] != -1)
					break;
			k = i;
		    for(j = i + 1;j < n;j ++)
			    if(mark[j] != -1 && mark[j] < mark[k])
				    k = j;

		    if(k == 1)
			{
				printf("Scenario #%d\n",counter ++);
			    printf("Frog Distance = %.3lf\n\n",mark[k]);
				break;
			}
		    for(i = 1;i < n;i ++)
				if(mark[i] != -1 && i != k && (graph[k][i] < mark[k] ? mark[k] : graph[k][i] ) < mark[i])//!!!!!!!
					mark[i] = (graph[k][i] < mark[k] ? mark[k] : graph[k][i] );
			mark[k] = -1;
		}
		scanf("%d",&n);
	}
	return 0;
}