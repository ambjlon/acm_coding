#include <stdio.h>

int main()
{
	int i,n;
	long long int x0,y0,x1,y1,x,y;

	while(scanf("%d",&n) != EOF)
	{
		printf("%d",n);
		scanf("%lld%lld%lld%lld",&x0,&y0,&x1,&y1);
		printf(" %.6lf %.6lf",(double)(x0+x1)/2,(double)(y0 + y1) / 2);
		for(i = 1;i <= n -2;i ++)
		{
			scanf("%lld%lld",&x,&y);
			printf(" %.6lf %.6lf",(double)(x+x1)/2,(double)(y + y1) / 2);
			x1 = x;
			y1 = y;
		}
		printf(" %.6lf %.6lf\n",(double)(x0+x)/2,(double)(y0 + y) / 2);
	}
	return 0;
}