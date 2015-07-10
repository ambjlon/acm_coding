#include <stdio.h>

typedef struct head
{
	int in;
	int a[101];
}Head;
int stack[101];
int main()
{
	Head b[101];
	int i;
	int n;
	int a,m,temp,e;
	
	
	scanf("%d",&n);
	while(n!=-1)
	{
		stack[0]=0;
		for(i=1;i<=100;i++)
		{
			b[i].in=0;
			b[i].a[0]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&m);
			b[m].in++;
			b[a].a[++b[a].a[0]]=m;
		}

		for(i=1;i<=3;i++)
			if(b[i].in==0)
				stack[++stack[0]]=i;

		while(stack[0]!=0)
		{
			temp=stack[stack[0]];
			stack[0]--;
			for(i=1;i<=b[temp].a[0];i++)
			{
				b[b[temp].a[i]].in--;
				if(b[b[temp].a[i]].in==0)
				stack[++stack[0]]=b[temp].a[i];
			}
		}


		scanf("%d",&e);
		
		if(b[e].in!=0&&b[e].a[0]!=0&&b[e].a[1]!=e)
			printf("No\n");
		else
			printf("Yes\n");
		scanf("%d",&n);
	}
	return 0;
}