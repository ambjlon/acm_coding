#include <stdio.h>
#include <memory.h>

char mod[100];
char result[100];
int num[100];
char flag[100];
int m,t,p;
int OrderRead();
void Display();
int main()
{
	int n,i,sum;


	scanf("%d",&n);
	getchar();
	while(1)
	{
		if(OrderRead())
		{
			sum = 0;
			for(i = 0;i < m;i ++)
				sum += num[i];
			p = sum;
			t = 0;
			Display();
		}
		else
			break;
	}
	return 0;
}
void Display()
{
	int i;
	if(t == p)
	{
		printf("%s\n",result);
		return;
	}
	for(i = 0;i < m;i ++)
		if(flag[i] == 0 || num[i] != 0)
		{
			result[t ++] = mod[i];
			num[i] --;
			flag[i] = 1;
			Display();
			t --;
			flag[i] = 0;
			num[i] ++;
		}
}
int OrderRead()
{
	int j,k,i = 0;
	char c;

	memset(mod,0,sizeof(mod));
	memset(num,0,sizeof(num));
	memset(flag,0,sizeof(flag));
	memset(result,0,sizeof(result));
	if(scanf("%c",&c) != EOF)
	{
	     mod[0] = c;
		 num[0] ++;
	}
	else
		return 0;
	while(scanf("%c",&c) && c != '\n')
	{
		for(k = 0;k <= i;k ++)
			if(c < mod[k])
			{
				for(j = i;j >= k;j --)
				{
					mod[j + 1] = mod[j];
					num[j + 1] = num[j];
				}
				num[k] = 0;
				break;
			}
			else if(mod[k] == c)
			{
				i --;
				break;
			}
			mod[k] = c;
			i ++;
		    num[k] ++;
	}
	m = i + 1;
	return 1;
}