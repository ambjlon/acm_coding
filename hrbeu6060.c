#include <stdio.h>
#include<memory.h>

int main()
{
	int i,j,k,n,max;
	int a[25],b[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

	
	scanf("%d",&n);
	while(n != 0)
	{
		memset(a,0,sizeof(a));
		max = -1;
		for(i = 2;i <= n;i ++)
		{
			k = i;
			for(j = 0;b[j] <= k;j ++)
			{
				if(k % b[j] == 0 && j > max)
					max = j;
				while(k % b[j] == 0)
				{
					a[j] ++;
					k = k / b[j];
				}
			}
		}
		printf("%3d! =",n);
		for(i = 0;i <= max;i ++)
		{
			if(i == 0)
			{
				printf("%3d",a[i]);
				continue;
			}
			if(i == 15)
			{
				printf("\n      ");
			    printf("%3d",a[i]);
				continue;
			}
			printf("%3d",a[i]);
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}