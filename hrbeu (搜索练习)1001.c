#include <stdio.h>

char map[60][60];
int n,m;
int counter;

void DFS(int ln,int col);
int main()
{
	int  i,j;

	while(scanf("%d%d",&n,&m) != EOF)
	{
		getchar();
		counter = 0;
		for(i = 1;i <= n;i ++)
		{
			for(j = 1;j <= m;j ++)
				scanf("%c",&map[i][j]);
			getchar();
		}

		for(i = 1;i <= n;i ++)
			for(j = 1;j <= m;j ++)
				if(map[i][j] == '@')
				{
					counter ++;
					DFS(i,j);
				}
		printf("%d\n",counter);
	}
	return 0;
}
void DFS(int ln,int col)
{
	map[ln][col] = '*';
	if((ln - 1) > 0 && map[ln - 1][col] == '@')
		DFS(ln - 1,col);
	if((col - 1) > 0 && map[ln][col - 1] == '@')
		DFS(ln,col - 1);
	if((col + 1) <= m && map[ln][col + 1] == '@')
		DFS(ln,col + 1);
	if((ln + 1) <= n && map[ln + 1][col] == '@')
		DFS(ln + 1,col);
}