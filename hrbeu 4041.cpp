#include <stdio.h>

int main()
{
	double a[40000],max,tmp,tt;
	int i,j,n;
	while(scanf("%d",&n)!= EOF)
	{
		max = -2122222229;
		tmp = 0;
		for(i = 1;i <= n;i ++)
			scanf("%lf",&a[i]);
		for(i = n;i >= 1;i --)
		{
			tmp += a[i];
			tt = tmp / (n - i + 1);
			if(tt > max)
				max = tt;
		}
		printf("%.6lf\n",max);
	}
}