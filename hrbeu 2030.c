#include <stdio.h>
#include <string.h>

int main()
{
	int i,j,k;
	int m,n;
	char s[100000],t[100000];

	while(scanf("%s",s) != EOF)
	{
		scanf("%s",t);
		m = strlen(s);
		n = strlen(t);
		if(m > n)
		{
			printf("No\n");
			continue;
		}



		k = 0;
		for(i = 0;s[i] != 0;i ++)
		{
			for(j = k; t[j] != 0;j ++)
				if(s[i] == t[j])
				{
					k = j + 1;
					break;
				}
			if(t[j] == 0)
			{
				printf("No\n");
				break;
			}
		}
		if(s[i] == 0)
			printf("Yes\n");



	}
	return 0;
}