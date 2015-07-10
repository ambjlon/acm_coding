#include <stdio.h>

int main()
{
	int i,j;
	int n;
	int m;
	int a[1000];
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=0;j<m;j++)
			scanf("%d",&a[j]);

		for(j=m-1;j>=1;j--)
			printf("%d ",a[j]);
		printf("%d\n",a[j]);
	}
	return 0;
}