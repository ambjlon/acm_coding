#include <stdio.h>

char pre[27];
char inor[27];
char beh[27];
int sp;

void k(int l,int r,int x);
int main()
{
	int i,n;
	while(scanf("%s%s",pre,inor)!=EOF)
	{
		for(n=0;pre[n]!=0;n++)
			;
		sp=0;
		k(0,n-1,0);
		for(i=n-1;i>=0;i--)
			printf("%c",beh[i]);
		printf("\n");
	}
	return 0;
}

void k(int l,int r,int x)
{
	if(l==r)
		beh[sp++]=pre[l];
	else if(r-l==1)
	{
		beh[sp++]=pre[l];
		beh[sp++]=pre[r];
	}
	else
	{
		int i;
		beh[sp++]=pre[l];
		for(i=x;i<=x+r-l;i++)
			if(inor[i]==pre[l])
				break;
		if(i==x+r-l)
			k(l+1,r,x);
		else if(i==x)
			k(l+1,r,x+1);
		else
		{
		k(l+i-x+1,r,i+1);
		k(l+1,l+i-x,x);
		}
	}
}