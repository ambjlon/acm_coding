#include <stdio.h>
int main()
{
	int i,j;
	char a[70];
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",a);
		printf("URL #%d\n",i);
		printf("Protocol = ");
		j=0;
		while(a[j]!=':')
			printf("%c",a[j++]);
		printf("\n");
		printf("Host     = ");
		j=j+3;
		while(a[j]!=':'&&a[j]!=0&&a[j]!='/')
			printf("%c",a[j++]);
		printf("\n");
		if(a[j]==0)
		{
			printf("Port     = <default>\n");
			printf("Path     = <default>\n");
		}
		else if(a[j]=='/')
		{
			printf("Port     = <default>\n");
			printf("Path     = ");
			j++;
			while(a[j]!=0)
				printf("%c",a[j++]);
			printf("\n");
		}
		else
		{
			printf("Port     = ");
			j++;
		    while(a[j]!='/'&&a[j]!=0)
			printf("%c",a[j++]);
			printf("\n");
			if(a[j]==0)
				printf("Path     = <default>\n");
			else
			{
				printf("Path     = ");
				j++;
				while(a[j]!=0)
					printf("%c",a[j++]);
				printf("\n");
			}

		}
		printf("\n");
	}
	return 0;
}