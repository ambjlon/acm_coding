#include <stdio.h>
#include <memory.h>

int a[101][101];
int b[101][101];
int main()
{
	int i,j,x,y,tmp,sum,n,max;
	while(scanf("%d",&n) != EOF)
	{
		memset(a,0,sizeof(a));
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				scanf("%d",&a[i][j]);
		max = -2012343211;
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
			{
				memset(b,0,sizeof(b));
				for(x = i;x < n;x ++)
				{
					tmp = 0;
					for(y = j;y < n;y ++)
					{
						tmp += a[x][y];
						sum = tmp + b[x - 1][y];
						b[x][y] = sum;
						if(sum > max)
							max = sum;
					}
				}
			}
		printf("%d\n",max);
	}
	return 0;
}