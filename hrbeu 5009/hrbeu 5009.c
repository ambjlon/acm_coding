
//arrange characters in alphabetic order
//hrbeu 5009
//Written by ChenJianglong 2009.5.19
#include <stdio.h>

int n;
char s[27];

void k(int l);
void order(char *s,int n);
int main()
{
	int i;
	int num;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		
		scanf("%s",s);
		for(n=0;s[n]!=0;n++)
			;
		order(s,n);
		printf("Case %d:\n",i);
		k(0);

	}
	return 0;
}
void k(int l)
{
	int i,j;
	char c;
	if(n-1-l==1)
	{
		if(s[l]==s[n-1])
			printf("%s\n",s);
		else
		{
			printf("%s\n",s);
			c=s[n-1];
			s[n-1]=s[l];
			s[l]=c;
			printf("%s\n",s);
		}
	}
	else
	{
		i=n-1;
		k(l+1);
		while(i>l)
		{
			if(s[i]!=s[l])
			{
			c=s[i];
			s[i]=s[l];
			s[l]=c;

			for(j=l+1;j<=(l+n)/2;j++)
			{
				c=s[j];
				s[j]=s[l+n-j];
				s[l+n-j]=c;
			}

			k(l+1);
			}
			i--;
		}
	}
}
void order(char *s,int n)
{
	int i,j,k;
	char c;
	for(i=1;i<=n-1;i++)
		for(j=0;j<i;j++)
		{
			if(s[j]>s[i])
			{
				c=s[i];
				for(k=i;k>=j+1;k--)
					s[k]=s[k-1];
				s[j]=c;
			}

		}
}