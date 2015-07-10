#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main()
{
    int a[102][102];
    int i,j,k,flag,t,p,counter;
    char c[100];
    
    while(scanf("%d%d",&p,&t) != EOF)
    {
		memset(a,0,sizeof(a));
		counter = 1;
		getchar();
		while(gets(c) && c[0] != 0)
		{
            sscanf(c,"%d%d",&i,&j);
			a[j][i] = 1;
		}
		for(i = 2;i <= p;i ++)
		{
			flag = 0;
			for(j = 1;j < i;j ++)
			if(a[0][j] == 0)
			{
				for(k = 1;k <= t;k ++)
					if(a[k][j] != a[k][i])
						break;
				if(k > t)
				{
					flag = 1;
					a[0][i] = 1;
					break;
				}
			}
			if(flag == 0)
				counter ++;
		}
		printf("%d\n",counter);
	}
    return 0;
}
