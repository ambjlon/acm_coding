
//Written by ChenJianglong 2009.5.21
#include <stdio.h>

int main()
{
	int i,j,k;
	int n;
	int count;
	int a[104];
	int b[104];
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		count=0;
		b[0]=a[0];
		for(i=1;i<n;i++)
		{
			for(j=0;j<=count;j++)
				if(a[i]==b[j])
					break;
				else if(a[i]<b[j])
				{
					for(k=count+1;k>=j+1;k--)
						b[k]=b[k-1];
					b[j]=a[i];
					count++;
					break;
				}
			if(j>count)
			{
				b[count+1]=a[i];
				count++;
			}
		}

		for(i=0;i<count;i++)
			printf("%d ",b[i]);
		printf("%d",b[i]);
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}