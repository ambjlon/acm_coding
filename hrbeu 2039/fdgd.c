#include <stdio.h>
#include<stdlib.h>


typedef struct fgh
{
	int tailvex,headvex;
	struct fgh *tlink,*hlink;
}Arc,*PArc;
typedef struct hfds
{
	PArc firstin,firstout;
	int flag;
}Vex,*PVex;
int stack[5001];
int collector[5001];
int count;

PVex DrawGraph(int v,int e);
void DestroyGraph(PVex grap);
void FDFS(PVex grap,int n);
void SDFS(PVex grap,int n);
int main()
{
	int i,j;
	int v,e;
	int flag;
	PVex grap;

	scanf("%d",& v);
	if(v == 0)
		return 0;
	scanf("%d",& e);
	while(1)
	{
		grap = DrawGraph(v,e);
		
		for(i = 1;i <= v;i ++)
			stack[i] = 0;
		count = 0;
		for(i = 1;i <= v;i ++)
			grap[i].flag = 0;
		for(i = 1;i <= v;i ++)
			if(grap[i].flag == 0)
				FDFS(grap,i);
		
		for(i = 1;i <= v;i ++)
			grap[i].flag = 0;
		flag = 0;
		for(i = v;i >= 1;i --)
		{
			count = 0;
			if(stack[i] != 0)
		  	  SDFS(grap,stack[i]);
			if(count > 1)
			{
				flag = flag + count;
				for(j =1 ;j <= count;j ++)
					printf("%d ",collector[j]);
			}
		}
		if(flag == 0)
			printf("\n");
		else
			printf("\n%d\n",flag);

		DestroyGraph(grap);

	    scanf("%d",& v);
	    if(v == 0)
	     	return 0;
	    scanf("%d",& e);
	}
}


PVex DrawGraph(int v,int e)
{
	int i;
	int a,b;
	PArc flag,temp;
	PVex grap = malloc(sizeof(Vex) * (v + 1));
	grap[0].flag = v;

	for(i = 1;i <= v;i ++)
		grap[i].firstin = grap[i].firstout = NULL;

	for(i = 0;i < e;i ++)
	{
		scanf("%d%d",& a,& b);
		temp = malloc(sizeof(Arc));
		temp ->headvex = b;
		temp ->tailvex = a;
		temp ->hlink = temp ->tlink = NULL;

		flag = grap[a].firstout;
		if(flag == NULL)
			grap[a].firstout = temp;
		else
		{
		while(flag ->tlink != NULL)
			flag = flag ->tlink;
		flag ->tlink = temp;
		}
		flag = grap[b].firstin;
		if(flag == NULL)
			grap[b].firstin = temp;
		else
		{
		while(flag ->hlink != NULL)
			flag = flag ->hlink;
		flag ->hlink = temp;
		}
	}
	return grap;
}

void DestroyGraph(PVex grap)
{
	int i;
	int v = grap[0].flag;
	PArc flag,temp;

	for(i = 1;i <= v;i ++)
	{
		flag = grap[i].firstout;
		while(flag != NULL)
		{
			temp = flag;
			flag = flag ->tlink;
			free(temp);
		}
	}
	free(grap);
}
void FDFS(PVex grap,int n)
{
	int i;
	PArc flag,temp;

	
	grap[n].flag = 1;
	flag = grap[n].firstout;
	while(flag != NULL)
	{
		if(grap[flag ->headvex].flag == 0)
			FDFS(grap,flag ->headvex);
		flag = flag ->tlink;
	}

	stack[++ count] = n;
}
void SDFS(PVex grap,int n)
{
	int i;
	PArc flag,temp;

	for(i = 1;i <= grap[0].flag;i ++)
		if(stack[i] == n)
		{
			stack[i] = 0;
			break;
		}
	collector[++ count] = n;
	grap[n].flag = 1;

	flag = grap[n].firstin;
	while(flag != NULL)
	{
		if(grap[flag ->tailvex].flag == 0)
			SDFS(grap,flag ->tailvex);
		flag = flag ->hlink;
	}
}