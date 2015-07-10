//this program is hard for me at first,it takes me one week to consider this
//program
// written by ChenJianglong 2009.3.31
#include <stdio.h>

int n;
int sum=0,num,length=0;
int kicks[60];
int part[60];

void getkicks(int *n,int kicks[]);
void sort(int kicks[],int n);
int solve(int k);

void main()
{
	int i,j;

	getkicks(&n,kicks);
	sort(kicks,n);

	for(i=1;i<=n;i++)
	sum+=kicks[i];
	kicks[n+1]=0;
	length=kicks[1];
	for(i=n+1;i>=2;i--)
	{
		length+=kicks[i];
		if(!(sum%length))
		{
			printf("TRY %d>>\n",length);//
			for(j=0;j<sum/length;j++)
				part[j]=0;
			if(solve(1)==1)
			{
				printf("%d",length);
				break;
			}
			else
				printf("TRY %d fail!!\n\n",length);//
		}
	}
}


void getkicks(int *n,int kicks[])
{
	int i;
	printf("input the number of the kicks :");
	scanf("%d",n);
	printf("input the length of the kicks:\n");
	for(i=1;i<=*n;i++)//here is *n
		scanf("%d",kicks+i);
}


void sort(int kicks[],int n)
{
	int k,i,j,temp;
	for(i=1;i<=n-1;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
			if(kicks[j]>kicks[k])
				k=j;
		if(k!=i)
		{
			temp=kicks[i];
			kicks[i]=kicks[k];
			kicks[k]=temp;
		}
	}
}
int solve(int k)
{
	int i;
	printf("--arrang the %dth kick..\n",k);//
	for(i=0;i<sum/length;i++)
	{
		if(part[i]+kicks[k]<=length)
		{
			printf("-the %dth kicks in the %dth initial kick\n",k,i);//
			part[i]+=kicks[k];
			if(k==n)
				return 1;
			if(solve(k+1)==1)
				return 1;
			printf("fail to arrange the %dth kicks in the %dth initial kick!!\n",k,i);//
			part[i]-=kicks[k];
		}
	}
	return 0;
}