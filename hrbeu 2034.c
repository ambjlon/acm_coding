#include <stdio.h>

int main()
{
	int i,k,n;
	double x[10000],y[10000];
	long long int a[100000],b[100000];

	while(scanf("%ld",&n) != EOF)
	{
		k = n;
		for(i = 1;i <= k;i ++)
			scanf("%lld%lld",&a[i],&b[i]);
		for(i = 1;i <= k;i ++)
		{
			a[i] *= 2;
			b[i] *= 2;
		}
		for(i = 1;i <= k -1;i ++)
			if(i % 2 == 1)
			{
				a[k] = a[k] - a[i];
				b[k] = b[k] - b[i];
			}
			else
			{
				a[k] = a[k] + a[i];
				b[k] = b[k] + b[i];
			}
		for(i = k;i >= 1;i --)
		{
			if(i == k)
			{
				x[n] = (double)a[i] / 2;
				y[n] = (double)b[i] / 2;
				n --;
			}
			else
			{
				x[n] = (double)a[i] - x[n + 1];
				y[n] = (double)b[i] - y[n + 1];
				n --;
			}	
		}
		printf("%d",k);
		for(i = 1;i <= k;i ++)
			printf(" %.6lf %.6lf",x[i],y[i]);
		printf("\n");
	}
	return 0;
}