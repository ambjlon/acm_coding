#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int a[60001];
struct PH
{
	int x,y;
	int id;
}ph[6501];
int b[10100];
int c[10100];
map<string,int>q;
void get(char *s)
{
	int len=0;
	char c;
	while((c=getchar())&&c!='[');
	while((c=getchar())&&c!=']')
	{
		s[len++]=c;
	}
	s[len]='\0';
}
char s[2000];
int main()
{
	int n,m,ma,i,len,sum,mi,x,y,j;
	scanf("%d ",&n);
	q.clear();
	for(i=0;i<n;i++)
	{
		get(s);
		q[s]=i;
		scanf("%d",&a[i]);
	}
	while(scanf("%d%d ",&m,&ma)==2)
	{
		len=0;
		mi=0;
		for(i=0;i<m;i++)
		{
			get(s);
			cin>>ph[i].x>>ph[i].y;
			ph[i].id=q[s];
			b[len++]=ph[i].x;
			b[len++]=ph[i].y;
		}
		sort(b,b+len);
		len=unique_copy(b,b+len,c)-c;
		for(i=0;i<len;i++)
		{
			x=c[i];
			sum=0;
			for(j=0;j<m;j++)
			{
				if(x>=ph[j].x&&x<=ph[j].y)
				{
					sum+=a[ph[j].id];
					
				}
			}
			if(sum>mi)mi=sum;
			if(sum>ma)
			{
				if(sum<=1)
				printf("The power will be out at time %d because the power is %d Watt and overloaded.\n",x,sum);
				else
				printf("The power will be out at time %d because the power is %d Watts and overloaded.\n",x,sum);
				break;
			}
		}
		if(i==len)
		{
			if(mi<=1)
			printf("The maximum power needed is %d Watt.\n",mi);
			else
			printf("The maximum power needed is %d Watts.\n",mi);
		}
	}
	return 0;
} 
