#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,k;
	int prime[5155];//50000以内的素数5133个
	FILE *p;
	p = fopen("D:\\out prime.txt","w");

	prime[1] = 2;
	k = 2;
	for(i = 3;i <= 50000;i ++)
	{
		for(j = 1;prime[j] <= sqrt(i);j ++)
			if(i % prime[j] == 0)
				break;
		if(prime[j] > sqrt(i))
			prime[k ++] = i;
	}
	for(i = 1;i < k;i ++)
		printf("%d\n",prime[i]);
	printf("Total :%d\n",k - 1);

	for(i = 1;i < k;i ++)
		fprintf(p,"%d,\n",prime[i]);
	fclose(p);
}
