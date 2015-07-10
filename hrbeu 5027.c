#include <stdio.h>
//#include <stdlib.h>

int main()
{
	int a[100000],n,i,b[100000],c,d;

	while(scanf("%d",&n) != EOF)
	{
		for(i = 0;i < 100000;i ++)
			b[i] = 0;
		for(i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		for(i = 2;i <= n -1;i ++)
		{
			if(a[i - 1] % 2)
				c = a[i - 1] / 2 + 1;
			else
				c = a[i - 1] / 2;
			b[i] = c + a[i + 1] / 2 ;
		}
		if(a[n] % 2)
				c = a[n] / 2 + 1;
		else
			c = a[n] / 2;
		b[1] = c + a[2] / 2;
		if(a[n-1] % 2)
				c = a[n-1] / 2 + 1;
		else
			c = a[n - 1] / 2;
		b[n] = c + a[1] / 2 ;
		for(i = 1;i <= n- 1;i ++)
			printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
}