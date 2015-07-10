#include <stdio.h>
#define INT_MAX 32767

int graph[50][50];

int main()
{
	int i,j,k,q;
	int max,temp;
	int x,y,z;
	int t,n,m;

	scanf("%d",&t);
	for(q = 1;q <= t;q ++)/*Ï¹ÑÛÑ½£¬²Ù£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡*/
	{
		scanf("%d",&n);/*line : n*/
		scanf("%d",&m);

		if(m == 0)
		{
			printf("No solution.\n");
			continue;
		}
		/*initialize graph[50][50]*/
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				if(i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = INT_MAX;

		for(j = 1;j <= m;j ++)
		{
			scanf("%d%d%d",&x,&y,&z);
			graph[x][y] = graph[y][x] = z;
		}
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				for(k = 0;k < n;k ++)
					if(graph[j][i] + graph[i][k] < graph[j][k])
						graph[j][k] = graph[j][i] + graph[i][k];

		max = INT_MAX;
		for(i = 0;i < n;i ++)
		{
			temp = 0;
			for(j = 0;j < n;j ++)
				if(graph[i][j] > temp)
					temp = graph[i][j];
			if(temp == INT_MAX)
			{
				printf("No solution.\n");
				break;
			}
			if(temp < max)
			{
				max = temp;
				k = i;
			}
		}
		if(i == n)
			printf("%d\n",k);
	}
	return 0;
}
