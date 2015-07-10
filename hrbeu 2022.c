#include <stdio.h>

char s[482][101];
char a[103],b[103];
char p[101],q[101];

int Add(int m,int n);
int Cmp(char *a,char *b);
int main()
{
	int i,j,n,m,count;
	for(i = 1;i < 482;i ++)
		for(j = 0;j < 482;j ++)
			s[i][j] = 0;
		s[1][100] = 1;
		s[2][100] = 2;
		for(i = 3;i < 482;i ++)
			if(Add(i - 2,i - 1))
			         ;
			else
				break;
			scanf("%s",a);
			scanf("%s",b);
			while(a[0] != '0' || b[0] != '0')
			{
				count = 0;
				for(i = 0;i < 101;i ++)
					p[i] = q[i] = 0;
				for(n = 0;a[n] != 0;n ++)
					;
				n --;
				for(m = 0;b[m] != 0;m ++)
					;
				m --;
				for(i = 100;n >= 0;i --,n --)
					p[i] = a[n] - 48;
				for(j = 100;m >= 0;j --,m --)
					q[j] = b[m] - 48;
				for(i = 1;i <= 479;i ++)
					if(Cmp(p,s[i]) == 1 || Cmp(p,s[i]) == 2)
						break;
					for(j = i,count = 0;j <= 479;j ++,count ++)
						if(Cmp(s[j],q) == 0)
							break;
					    printf("%d\n",count);
						scanf("%s",a);
						scanf("%s",b);
			}
			return 0;
}
int Add(int m,int n)
{
	int i,j,carry,tmp;
	
	for(j = 0;s[n][j] == 0;j ++)
		;
	carry = 0;
	for(i = 100;i >= j && i >= 0;i --)
	{
		tmp = carry + s[n][i] + s[m][i];
		s[n + 1][i] = tmp % 10;
		carry = tmp / 10;
	}
	if(i < 0)
		return 0;
	if(carry != 0)
		s[n + 1][i] = carry;
	return 1;
}
int Cmp(char *a,char *b)
{
	int i,j,n,m;
	for(n = 0;a[n] == 0;n ++)
		;
	for(m = 0;b[m] == 0;m ++)
		;
	if(n < m)
		return 0;//a > b
	else if(n > m)
		return 1;//a < b
	else
	{
		for(i = n;i<= 100;i ++)
			if(a[i] > b[i])
				return 0;
			else if(a[i] < b[i])
				return 1;
			else
				;
			return 2;//a = b
	}
}
