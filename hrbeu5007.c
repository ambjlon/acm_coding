#include <stdio.h>

int main()
{
	int i,j;
	char a[101],c;
	int n,count;

	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%s",a);
		c=a[0];
		j=1;
		count = 1;
		while(c!=0)
			if(a[j++]==c)
				count++;
			else
			{
				if(count != 1)
				printf("%d%c",count,c);
				else
					printf("%c",c);
				c = a[j-1];
				count = 1;
			}
		printf("\n");
	}
	return 0;
}