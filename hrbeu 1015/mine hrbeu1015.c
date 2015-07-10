#include <stdio.h>
#define SW(min,max) {int t;t=min;min=max;max=t;}

int main()
{
	int count;
	int min,max;
	while(1)
	{
		scanf("%d%d",&min,&max);
		if(min==0&&max==0)
			break;
		if(min>=max)
		SW(min,max);
		
		if(min==0||max/min>=2)
			printf("Stan wins\n");
		else
		{
			count = 0;
			while(min==0||max/min<2)
			{
				count++;
				max=max-min;
				if(min>=max)
				SW(min,max);
			}
			if(count%2!=0)
			    printf("Ollie wins\n");
			else
				printf("Stan wins\n");
		}
	}
	return 0;
}