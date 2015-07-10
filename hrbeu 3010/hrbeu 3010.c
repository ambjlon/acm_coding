#include <stdio.h>
#include <math.h>

#define PI 3.1415

int main()
{
	int n,i;
	double sita,aif;
	double dig,tx,ty;
	int a,b,x,y,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&x,&y);
		if(a>b)
		{
			t=a;
			a=b;
			b=t;
		}
		if(x>y)
		{
			t=x;
			x=y;
			y=t;
		}
		if(a<x&&b<y)
			printf("Box cannot be dropped.\n");
		else if(a>=x&&b>=y)
			printf("Escape is possible.\n");
		else
		{
			dig=sqrt((double)x*x+(double)y*y);
			aif=sita=atan((double)x/y);
			for(;sita<=aif+PI/4;sita=sita+0.001)
			{
				ty=dig*cos(2*aif-sita);
				tx=dig*sin(sita);
				if(ty<=b&&tx<=a)
				{
					printf("Escape is possible.\n");
					break;
				}
			}
			if(sita>aif+PI/4)
				printf("Box cannot be dropped.\n");
		}
	}
	return 0;
}