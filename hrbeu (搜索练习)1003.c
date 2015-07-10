#include <stdio.h>

int domino[12][12];
int main()
{
	int i,j,k,p;
	int n,m;

	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(i = 0;i < 12;i ++)
		{
			domino[i][0] = 0;
			domino[i][11] = 0;
		}
		for(j = 0;j < 12;j ++)
		{
			domino[11][j] = 0;
			domino[0][j] = 0;
		}

		for(i = 1;i <= n;i ++)
			for(j = 1;j <= m;j ++)
				scanf("%d",&domino[i][j]);

		scanf("%d%d",&i,&j);
		while(domino[i][j] != -1 && domino[i][j] != 0)
		{
			k = i;
			p = j;
			if(domino[i][j] == 1)
				i = i - 1;
			else if(domino[i][j] == 2)
				i = i + 1;
			else if(domino[i][j] == 3)
				j = j + 1;
			else if(domino[i][j] == 4)
				j = j - 1;
			else
			{
				printf("Good\n");
				break;
			}
			domino[k][p] = -1;
		}
		if(domino[i][j] == -1 || domino[i][j] == 0)
			printf("My God\n");
	}
	return 0;
}