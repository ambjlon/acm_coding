#include <stdio.h>
int main()
{
	int i,j,k,m,t;
	int carry,temp;
	char c;
	int n;
	char a[10];
	char b[10];
	int x,y;

	scanf("%d",&n);
	getchar();

	for(i=1;i<=n;i++)
	{
		//必须以整数读入
		scanf("%d%d",&x,&y);
		j=9;
		while(x!=0)
		{
			c=x%10+48;
			x=x/10;
			a[j--]=c;
		}
		k=9;
		while(y!=0)
		{
			c=y%10+48;
			y=y/10;
			b[k--]=c;
		}
		j++;
		k++;
		
		for(t=j,m=9;t<=(j+9)/2;t++,m--)
		{
			c=a[t];
			a[t]=a[m];
			a[m]=c;
		}
		
		for(t=k,m=9;t<=(k+9)/2;t++,m--)
		{
			c=b[t];
			b[t]=b[m];
			b[m]=c;
		}

		carry=0;
		m=j<=k?j:k;
		for(t=m-1;t<j;t++)
			a[t]='0';
		for(t=m-1;t<k;t++)
			b[t]='0';
		for(k=9;k>=m-1;k--)
		{
			temp=(a[k]-48)+(b[k]-48)+carry;
			carry=temp/10;
			a[k]=temp%10;
		}
		k=a[m-1]==0?m:m-1;
		for(j=9;j>=k;j--)
			if(a[j]!=0)
				break;
		x=0;
		for(t=j;t>=k;t--)
		{
			x=x*10;
			x=x+a[t];
		}

		printf("%d\n",x);
	}

	return 0;
}	
