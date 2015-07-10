
#include <stdio.h>
#include <memory.h>
char graph[54][54];
int flag[54][54];
int m,n;

void Dfs(int i,int j);
int up(int i,int j);
int down(int i,int j);
int left(int i,int j);
int right(int i,int j);
int main()
{
	int i,j;
	int rst;
	while(scanf("%d%d",&m,&n) && m != -1 && n != -1)
	{
		getchar();
		for(i = 1;i <= m;i ++)
		{
			for(j = 1;j <= n;j ++)
				scanf("%c",&graph[i][j]);
			getchar();
		}
		rst = 0;
		memset(flag,0,sizeof(flag));
		for(i = 1;i <= m;i ++)
			for(j = 1;j <= n;j ++)
			{
				if(flag[i][j] == 0)
				{
					rst ++;
					Dfs(i,j);
				}
			}
		printf("%d\n",rst);
	}
	return 0;
}
void Dfs(int i,int j)
{
	flag[i][j] = 1;
	if(i - 1 >= 1 && flag[i - 1][j] == 0 && up(i,j))
		Dfs(i - 1,j);
	if(i + 1 <= m && flag[i + 1][j] == 0 && down(i,j))
		Dfs(i + 1,j);
	if(j - 1 >= 1 && flag[i][j - 1] == 0 && left(i,j))
		Dfs(i,j - 1);
	if(j + 1 <= n && flag[i][j + 1] == 0 && right(i,j))
		Dfs(i,j + 1);
}
int up(int i,int j)
{
	if(i - 1 < 1)
		return 0;
	if(graph[i][j] == 'A' || graph[i][j] == 'B' || graph[i][j] == 'E' || graph[i][j] == 'G' || graph[i][j] == 'H' ||graph[i][j] == 'J' || graph[i][j] == 'K')
	{
		if(graph[i - 1][j] == 'C' || graph[i - 1][j] == 'D' || graph[i - 1][j] == 'E' || graph[i - 1][j] == 'H' || graph[i - 1][j] == 'I' || graph[i - 1][j] == 'J' || graph[i - 1][j] == 'K')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int down(int i,int j)
{
	if(i + 1 > m)
		return 0;
	if(graph[i][j] == 'C' || graph[i][j] == 'D' || graph[i][j] == 'E' || graph[i][j] == 'H' || graph[i][j] == 'I' ||graph[i][j] == 'J' || graph[i][j] == 'K')
	{
		if(graph[i + 1][j] == 'A' || graph[i + 1][j] == 'B' || graph[i + 1][j] == 'E' || graph[i + 1][j] == 'G' || graph[i + 1][j] == 'H' || graph[i + 1][j] == 'J' || graph[i + 1][j] == 'K')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int left(int i,int j)
{
	if(j - 1 < 1)
		return 0;
	if(graph[i][j] == 'A' || graph[i][j] == 'C' || graph[i][j] == 'F' || graph[i][j] == 'G' || graph[i][j] == 'H' || graph[i][j] == 'I' || graph[i][j] == 'K')
	{
		if(graph[i][j - 1] == 'B' || graph[i][j - 1] == 'D' || graph[i][j - 1] == 'F' || graph[i][j - 1] == 'G' || graph[i][j - 1] == 'I' || graph[i][j - 1] == 'J' || graph[i][j - 1] == 'K')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int right(int i,int j)
{
	if(j + 1 > n)
		return 0;
	if(graph[i][j] == 'B' || graph[i][j] == 'D' || graph[i][j] == 'F' || graph[i][j] == 'G' || graph[i][j] == 'I' || graph[i][j] == 'J' || graph[i][j] == 'K')
	{
		if(graph[i][j + 1] == 'A' || graph[i][j + 1] == 'C' || graph[i][j + 1] == 'F' || graph[i][j + 1] == 'G' || graph[i][j + 1] == 'H' || graph[i][j + 1] == 'I' || graph[i][j + 1] == 'K')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

