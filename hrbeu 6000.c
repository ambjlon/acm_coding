#include <stdio.h>

int main()
{
	int i,j,m;
	int k,counter;
	int max,temp,up,dowm;

	while(scanf("%d%d",&i,&j) != EOF)
	{
		down = i;
		up = j;
		if(i > j)
		{
			temp = i;
			i = j;
			j = temp;
		}
		max = 0;
		for(m = i ;m <= j;m ++)
		{
			k = m;
			counter = 0;
			while(1)
			{
				counter ++;
				if(k == 1)
					break;
				else if(k % 2 == 1)
					k = 3 * k + 1;
				else
					k = k / 2;
			}
			if(counter >= max)
				max = counter;
		}
		printf("%d %d %d\n",down,up,max);
	}
	return 0;
}