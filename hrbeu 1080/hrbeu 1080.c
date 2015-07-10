#include <stdio.h>

int main()
{

	long i,j;
	long n,rst;
	long counter,temp;
	long var;
	
	scanf("%d",&n);
	while(n != 0)
	{
		var = n;
		rst = 1;
		for(i = 2; i<= var;i++)
		{
			counter = 0;
			while(!(n % i))
			{
				n = n / i;
				counter++;
			}
			if(counter != 0)
			{
				temp = 1;
				for(j = 1;j <= counter - 1;j++)
					temp = temp * i;
				rst = rst * (temp * i - temp);

				var = var / (temp * i);
				
			}
		}
		printf("%d\n",rst);
	    scanf("%d",&n);
	}
	return 0;
}