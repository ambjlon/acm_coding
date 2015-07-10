#include <stdio.h>
int main()
{
	int n,i;
	int flag[1000005];
	int f0=7;
	int f1=11;
	int res;
	flag[0]=0;
	flag[1]=0;
	for(i=2;i<=1000000;i++)
	{
		res=f0+f1;
	    f0=f1;
		f1=res;
		if(res%3==0)
			flag[i]=1;
		else
			flag[i]=0;
	}
	while(scanf("%d",&n)!=EOF)
	if(flag[n])
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
