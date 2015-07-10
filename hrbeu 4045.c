#include <stdio.h>

int main()
{
	int i,j,n,m,sum;

	scanf("%d",&n);
	for(i = 1;i <= n;i ++)
	{
		sum = 0;
		scanf("%d",&m);
		for(j = 2;j * j < m ;j ++)
			if(m % j == 0)
				sum = sum + j + (m / j);
		if(m != 1)
			sum += 1;
		if(j * j == m)
			sum += j;

		printf("%d\n",sum);
	}
	return 0;
}