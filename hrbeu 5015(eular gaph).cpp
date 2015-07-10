//欧拉图满足 ：1，是强连通图 2.每个顶点出入度相同
//written by ChenJianglong 2009.10.18
#include <stdio.h>
#include <memory.h>

int v[150];
int stack[150];
int a[150][150];
int n,m,c;

void Convert();
bool Connect();
bool Elur();
void DFS(int start);
int main()
{
	int t;
	int k;
	scanf("%d",&t);
	for(k = 0;k < t;k ++)
	{
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		memset(stack,-1,sizeof(stack));
		scanf("%d%d",&n,&m);
		int i,j,p;
		for(p = 0;p < m;p ++)
		{
			scanf("%d%d",&i,&j);
			a[i - 1][j - 1] = 1;
		}
		if(Connect() && Elur())
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

void Convert()
{
	int i,j,t;
	for(i = 0;i < n;i ++)
		for(j = i + 1;j < n;j ++)
		{
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
}
bool Connect()//判强连同
{
	int i;
	c = 0;
	DFS(0);
	for(i = 0;i < n;i ++)
		if(v[i] != 1)
			break;
	if(i < n)
		return false;
	Convert();
	DFS(stack[n - 1]);
	for(i = 0;i < n;i ++)
		if(v[i] != 1)
			break;
	if(i < n)
		return false;
	else
		return true;
}
bool Elur()
{
	Convert();
	int in[150],out[150],i,j;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for(i = 0;i < n;i ++)
		for(j = 0;j < n;j ++)
			if(a[i][j] == 1)
			{
				out[i] ++;
				in[j] ++;
			}
	for( i = 0;i < n;i ++)
		if(in[i] != out[i])
			break;
	if(i < n)
		return false;
	else
		return true;
}
void DFS(int start)
{
	int i;
	for( i = 0;i < n;i ++)
		if(a[start][i] == 1 && v[i] == 0)
		{
			v[i] = 1;
			stack[c++] = i;
			DFS(i);
		}
}