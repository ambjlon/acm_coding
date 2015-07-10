#include <stdio.h>

int main()
{
	int i,j;
	int n,sum,m,p;
	double x;
	char s[100];

	while(scanf("%d",&n) != EOF)
	{
		sum = 0;
		for(i = 1;i <= n;i ++)
		{
			scanf("%d",&m);
			sum = sum + m;
		}
		x = (double)sum / 6;
		p = (int)(x * 1000);
		if(p % 10 > 4)
			p = p + 10;
		p = p / 10;
		j = 0;
		do
		{
			s[j ++] = '0' + p % 10;
			p = p /10;
		}while(p != 0);
		j --;
		if(j < 2)
			while(j != 2)
			{
				j ++;
				s[j] = '0';
			}
		for(i = 0;i <= j;i ++)
		{
			if(i == 0)
			{
			    if(s[i] == '0')
					;
				else
					printf("%c",s[i]);
			}
			if(i == 1)
				printf("%c.",s[i]);
			if(i > 1)
				printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}