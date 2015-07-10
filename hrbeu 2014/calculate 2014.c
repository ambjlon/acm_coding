#include <stdio.h>
int main()
{
	int i,j;
	int sum;
	for(i = 2;;i ++)
	{
		sum = 0;
		for(j = i;j <= 2 * i - 1;j++)
			sum += j;
		for(j = i;j < 2 * i - 1;j ++)
			sum += j;
		printf("%d  %d\n",i,sum);
		if (sum > 100000)
			break;
	}
}