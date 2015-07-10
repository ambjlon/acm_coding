#include <stdio.h>

int main()
{
	int m;
	int n;
	float sum;
	double per;/*double is necessary,here!*/
	int i,j,k;
	int a[1001];
	while(scanf("%d",&m)!=EOF)
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d",&n);
			sum=0;
			k=0;
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[j]);
				sum=sum+a[j];
			}
			sum=sum/n;
			for(j=1;j<=n;j++)
				if(a[j]>sum)
					k++;
			per=(double)k/n;
			printf("%5.3f%%\n",per*100);
		}
	}
	return 0;
}
