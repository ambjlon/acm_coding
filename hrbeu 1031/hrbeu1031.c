#include <stdio.h>

int compare(char *p,char *m,int count);
int compare_a(char *p,char *m,int count2);
int main()
{
	int i,j;
	int b,carry;
	int count1,count2;
	char p[1001],m[1001];

	scanf("%d",&b);
	while(b!=0)
	{
		getchar();
		scanf("%s",p);
		count1 = 0;
		for(i = 0;p[i] != 0;i++)
		{
			count1 ++;
			p[i]=p[i]-48;
		}
		getchar();
		scanf("%s",m);
		count2 = 0;
		for(i=0;m[i] != 0;i ++)
		{
			count2 ++;
			m[i]=m[i]-48;
		}

		while(1)
		{
			if((count1 < count2)||(count1 == count2&&compare(p,m,count1) == 2))
			{
				for(i=0;i<count1;i++)
					printf("%d",p[i]);
				printf("\n");
				break;
			}
		    else if(count1 == count2&&compare(p,m,count1) == 3)
			{
			    printf("0\n");
				break;
			}
			else
			{
			if(compare_a(p,m,count2)==1)
			for(i=count2;i<count1;i++)
				m[i]=0;
			else
			{
				for(i=count2;i>=1;i--)
					m[i]=m[i-1];
				for(i=count2+1;i<count1;i++)
					m[i]=0;
				m[0]=0;
			}
			carry=0;
			for(i=count1-1;i>=0;i--)
			{
				p[i]=p[i]-carry;
				if(p[i]>=m[i])
				{
					p[i]=p[i]-m[i];
					carry=0;
				}
				else
				{
					p[i]=p[i]+b;
					p[i]=p[i]-m[i];
					carry=1;
				}
			}
			for(i=0;i<count1;i++)
				if(p[i]>0)
					break;
			count1=count1-i;
			for(j=0;j<count1;j++,i++)
				p[j]=p[i];
			if(m[0]==0)
			for(j=0;j<count2;j++)
				m[j]=m[j+1];
			}
		}

	scanf("%d",&b);
	}
	return 0;
}
int compare(char *p,char *m,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(p[i]>m[i])
			return 1;//p>m
		else if(p[i]<m[i])
			return 2;//p<m
		else
			;
	}
	return 3;//p==m
}
int compare_a(char *p,char *m,int count2)
{
	int i;
	for(i=0;i<count2;i++)
	{
		if(p[i]>m[i])
			return 1;//can
		else if(p[i]<m[i])
			return 2;//cannot
		else
			;
	}
	return 1;
}