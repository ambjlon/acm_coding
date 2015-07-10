#include <stdio.h>
#include <math.h>

int k(int p);
int a[500008];
int main()
{
	int i;
	int n;
	for(i=1;i<=500008;i++)
		a[i] = -1;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=3;i<=n/2;i=i+2)
			if(k(i)&&k(n-i))
			{
				printf("%d = %d + %d\n",n,i,n-i);
			    break;
			}
		scanf("%d",&n);
	}
	return 0;
}
int k(int p)
{
	if(a[(p-1)/2]==1)
		return 1;
	else if(a[(p-1)/2]==0)
		return 0;
	else
	{
	int i;
	int m;
	m=(int)sqrt((float)p);
	for(i=2;i<=m;i=i+1)	
		if(!(p%i))
		{
			a[(p-1)/2]=0;
			return 0;
		}
	a[(p-1)/2]=1;
	return 1;
	}
}