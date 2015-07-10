#include <stdio.h>
int fabci(int n);
int main()
{
	int n;
	for(n=0;n<=100;n++)
	//while(scanf("%d",&n)!=EOF)
	if(fabci(n)%3==0)
		printf("%d <%d>:yes\n",n,fabci(n));
	else
		printf("%d <%d>:no\n",n,fabci(n));

	return 0;
}
int fabci(int n)
{
	if(n==0)
		return 7;
	else if(n==1)
		return 11;
	else
	{
		int i;
		int f0=7;
		int f1=11;
		int res;
		for(i=2;i<=n;i++)
		{
			res=f0+f1;
			f0=f1;
			f1=res;
		}
		return res;
	}
}