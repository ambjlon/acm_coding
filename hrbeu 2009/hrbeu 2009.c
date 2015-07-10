#include <stdio.h>

int main()
{
	int i,j;
    int n;
	int a[101][101];
	int sum;
	int count;
	int ln,col;

	scanf("%d",&n);
	while(n!=0)
	{
		ln=-1;
		col=-1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);

		count=0;
		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
				sum+=a[i][j];
			if(sum%2!=0)
			{
				count++;
				if(count==1)
				ln=i;
			}
			if(count>1)
			{
				printf("Corrupt\n");
				break;
			}
		}
		if(i!=n)
		{
		scanf("%d",&n);
		continue;
		}

		count=0;
		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
				sum+=a[j][i];
			if(sum%2!=0)
			{
				count++;
				if(count==1)
				col=i;
			}
			if(count>1)
			{
				printf("Corrupt\n");
				break;
			}
		}
		if(i!=n)
		{
		scanf("%d",&n);
		continue;
		}
		if(ln==-1&&col==-1)
		printf("OK\n");
		if(ln!=-1&&col!=-1)
			printf("Change bit (%d,%d)\n",ln+1,col+1);
		if((ln==-1&&col!=-1)||(ln!=-1&&col==-1))
			printf("Corrupt\n");

		scanf("%d",&n);

	}
	return 0;
}