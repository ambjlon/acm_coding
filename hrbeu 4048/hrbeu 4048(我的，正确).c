#include <stdio.h>

int a[60],b[60];
long long  cnm(int n,int k);//还有Long long?????????????????
int main()
{
	int i,n,k,mp;
	long long sum1;
	double sum;
	
	scanf("%d%d",&n,&k);
	while(n != -1)
	{
		sum = 0;
		sum1 = 1;
		mp = 0;
		for(i = 1; i <= n;i ++)
			scanf("%d",&a[i]);
		for(i = 1;i <= n;i ++)
			scanf("%d",&b[i]);
		for(i = 1;i <= n;i ++)
			mp += a[i];
		sum = cnm(mp,k);
		for(i = 1;i <= n;i ++)
			sum1 = sum1 * cnm(a[i],b[i]);
		printf("%.5lf\n",sum1 / sum);
		scanf("%d%d",&n,&k);
	}
	return 0;
}
long long cnm(int n,int k)
{
	if (n < k)
		return 0;//操，这个还卡!!!!!!!!!!!!!!!
	long long result;
	int i,j;
	int m = n-k,t;
	if(m < k)
	{
		t = k;
		k = m;
		m = t;
	}
	result=1;
	for(i=1,j=n;i<=k;i++,j--)
		result=result*j/i;
	return result;
}