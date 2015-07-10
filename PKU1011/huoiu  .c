#include <stdio.h>

int sum=0,num,length=0;
int kicks[60];

void main()
{
	int n;
	int part[60];
	int i,j;

	getkicks(&n,kicks);
	sort(kicks,n);

	for(i=1;i<=n;i++)
	sum+=kicks[i];
	for(i=1;i<=n;i++)
	{
		length+=kicks[i];
		if(!(sum%length))
		{
			for(j=0;j<60;j++)
				part[j]=0;
			if(solve(1,1)==1)
		}
	}
}


void getkicks(int *n,int kicks[])
{
	int i;
	printf("input the number of the kicks :");
	scanf("%d",n);
	printf("input the length of the kicks:\n");
	for(i=1;i<=n;i++)
		scanf("%d",kicks+i);
}


void sort(int kicks[],int n)
{
	int k,i;
	for(i=1;i<=n-1;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
			if(kicks[j]>kicks[i])
				k=j;
		if(k!=i)
		{
			temp=kicks[i];
			kicks[i]=kicks[j];
			kicks[j]=temp;
		}
	}
}
int solve(int k,int m)
{
	if(part[m]+kicks[k]<=length)
	{
		part[m]+=kicks[k];
		ifsolve(k+1,m)
	}
	if(part[m]+kicks[k]>length)
		solve(k+1,m);
}