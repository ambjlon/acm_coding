#include <stdio.h>

typedef struct rect
{
	int x1,y1,x2,y2;
}Rect;
typedef struct point
{
	int x,y;
}Point;
int main()
{
	int i,j;
	int n,m;
	Rect a[11];
	Point b[55];

	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d%d",&b[i].x,&b[i].y);

		for(i=0;i<m;i++)
		{
			for(j=n-1;j>=0;j--)
				if(b[i].x>=a[j].x1&&b[i].x<=a[j].x2&&b[i].y<=a[j].y2&&b[i].y>=a[j].y1)
				{
					printf("%d\n",j);
				    break;
				}
			if(j<0)
				printf("%d\n",-1);
		}
		scanf("%d",&n);
	}
	return 0;
}