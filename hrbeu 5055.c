#include <stdio.h>

int a[101][101],p,q,sx,sy,fx,fy;
int min,flag;
void Dfs(int x,int y,int t);
int main()
{
	int i,j,k,n,m,x,y;

	scanf("%d",&n);
	for(i = 1;i <= n;i ++)
	{
		min = 2119999999;
		scanf("%d%d",&p,&q);
		for(j = 1;j <= p;j ++)
			for(k = 1;k <= q;k ++)
				a[j][k] = 0;
		scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
		scanf("%d",&m);
		for(k = 1;k <= m;k ++)
		{
			scanf("%d%d",&x,&y);
			a[x][y] = 1;
		}
		Dfs(sx,sy,-1);
		if(min == 2119999999)
			printf("can not reach!\n");
		else
			printf("%d\n",min);
	}
	return 0;
}
void Dfs(int x,int y,int t)
{
	int temp;
	//if(min == 1 || min == 0)
	//	return ;
	t = t + 1;
	if(x == fx && y == fy)
	{
		flag = 0;
		if(t <= min)
			min = t;
	}
	else
	{
		a[x][y] = -1;
		temp = flag = 1;
		if(x - 1 > 0 && a[x - 1][y] != 1)
		{
			if(x - 2 > 0 && y - 1 > 0 && a[x - 2][y - 1] == 0)
				Dfs(x - 2,y - 1,t);
			if(x - 2 > 0 && y + 1 <= q && a[x - 2][y + 1] == 0)
				Dfs(x - 2,y + 1,t);
		}
		if(y + 1 <= q && a[x][y + 1] != 1)
		{
			if(x - 1 > 0 && y + 2 <= q && a[x - 1][y + 2] == 0)
		    	Dfs(x - 1,y + 2,t);
			if(x + 1 <= p && y + 2 <= q && a[x + 1][y + 2] == 0)
				Dfs(x + 1,y + 2,t);
		}
		if(x + 1 <= p && a[x + 1][y] != 1)
		{
			if(x + 2 <= p && y + 1 <= q && a[x + 2][y + 1] == 0)
				Dfs(x + 2,y + 1,t);
			if(x + 2 <= p && y - 1 > 0 && a[x + 2][y - 1] == 0)
		    	Dfs(x + 2,y - 1,t);
		}
		if(y - 1 > 0 && a[x][y - 1] != 1)
		{
			if(x + 1 <= p && y - 2 > 0 && a[x + 1][y - 2] == 0)
				Dfs(x + 1,y - 2,t);
			if(x - 1 > 0 && y - 2 > 0 && a[x - 1][y - 2] == 0)
				Dfs(x - 1,y - 2,t);
		}
	if(flag != temp)
			a[x][y] = 0;
	}
	return ;
}