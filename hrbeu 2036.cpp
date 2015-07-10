#include <stdio.h>

int main()
{
	unsigned long  int  n,m,i,j,sum,ans;
    scanf("%lld %lld",&n,&m);
	while (1)
	{
		if(n == 0 && m == 0)
			break;
    sum=m+n;
    if(m>n)
	m=n;
    n=sum;
    ans=1;
	for(j = sum,i = 1;i <= m;j --,i ++)
		ans = ans * j / i;
    printf("%lld\n",ans);
	scanf("%lld %lld",&n,&m);
	}
	return  0;
}