//最小生成树
//Written by ChenJianglong 2009.6.19
#include <stdio.h>
#include <math.h>

typedef struct edge
{
	double lowcost;
	int adjvertex;
}Edge;
typedef struct heoo
{
	double x,y;
}Coordinate;

Coordinate ver[100];
double grap[100][100];
Edge a[100];

int main()
{
	int i,j,k;
	int n;
	double sum,min;

	scanf("%d",&n);
	while(n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&ver[i].x,&ver[i].y);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				grap[j][i]=grap[i][j]=sqrt((ver[i].x-ver[j].x)*(ver[i].x-ver[j].x)+(ver[i].y-ver[j].y)*(ver[i].y-ver[j].y));

       
		a[0].adjvertex=-1;
		a[0].lowcost=0;
		for(i=1;i < n;i++)
		{
			a[i].adjvertex=0;
			a[i].lowcost=grap[0][i];
		}
		min=a[1].lowcost;
		j=1;
		for(i=2;i<n;i++)
			if(a[i].lowcost<min)
			{
				j=i;
				min=a[i].lowcost;
			}
		sum=sum+min;
		a[j].lowcost=0;
		for(i=0;i<n;i++)
			if(grap[j][i]<a[i].lowcost)
			{
				if(j == i)
					continue;
				a[i].adjvertex=j;
				a[i].lowcost=grap[j][i];
			}

		for(k=2;k < n;k ++)
		{
			for(j=0;j<n;j++)
				if(a[j].lowcost!=0)
					break;
			min = a[j].lowcost;
			for(i = j + 1;i < n;i ++)
				if(a[i].lowcost < min && a[i].lowcost != 0)
				{
					j=i;
					min=a[i].lowcost;
				}
			sum = sum + min;

			a[j].lowcost=0;
			for(i = 0;i < n;i ++)
				if(grap[j][i] < a[i].lowcost)
				{
					if(j == i)
					continue;
					a[i].adjvertex=j;
					a[i].lowcost=grap[j][i];
				}
		}

		printf("%.2lf\n",sum);
		scanf("%d",&n);
	}
	return 0;
}