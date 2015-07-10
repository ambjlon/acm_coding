#include <stdio.h>

int main()
{
	int i,j;
	int n,k;
	int sum,temp;


	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		sum=1;
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		printf("%d\n",sum-k);
	}
	return 0;
}