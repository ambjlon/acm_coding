#include <stdio.h>
#include <memory.h>

int a[300];
char b[300];
int d[300][300][2];

int main()
{
	int i,j,k,x,y,n;
	int max,min,tpmin,tpmax,t1,t2,t3,t4;
	while(scanf("%d",&n) != EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		for(i = 0;i < n - 1;i ++)
		{
			scanf("%d",&a[i]);
			getchar();
			scanf("%c",&b[i]);
			getchar();
		}
		scanf("%d",&a[i]);
		for(i = 0;i < n;i ++)
		{
			d[i][i][0] = a[i];
			d[i][i][1] = a[i];
		}
		for(k = 1;k < n;k ++)
			for(i = 0,j = k;i < n - k;i ++,j ++)//deal with d[i][j]
			{
				max = -2122222222;
				min = 2122222222;
				for(x = i,y = i + 1;x < j;x ++,y ++ )
				{
					if(b[x] == '+')
					{
						tpmin = d[i][x][0] + d[y][j][0];
						tpmax = d[i][x][1] + d[y][j][1];
					}
					else
					{
						t1 = d[i][x][0] * d[y][j][0];
						t2 = d[i][x][0] * d[y][j][1];
						t3 = d[i][x][1] * d[y][j][0];
						t4 = d[i][x][1] * d[y][j][1];
						tpmin = ((t1<t2?t1:t2)<t3?(t1<t2?t1:t2):t3)<t4?((t1<t2?t1:t2)<t3?(t1<t2?t1:t2):t3):t4;
						tpmax = ((t1>t2?t1:t2)>t3?(t1>t2?t1:t2):t3)>t4?((t1>t2?t1:t2)>t3?(t1>t2?t1:t2):t3):t4;
					}
					if(tpmin < min)
						min = tpmin;
					if(tpmax > max)
						max = tpmax;
					d[i][j][0] = min;
				    d[i][j][1] = max;
				}
			}
			printf("%d\n",d[0][n-1][1]);
	}
	return 0;
}