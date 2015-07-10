#include<iostream>
#include <memory.h>//!!!!!!!!!!!!!
#include<queue>
using namespace std;

char flag[300][300];//!!!!!!!!!!!!
/**************************************/
struct Node{int c, m;};
int n, h, c, m;
int bfs();
/**************************************/
int bfs()
{
	if(m >= h-1) return -1;
	queue<Node> q;
	Node dad, son;
	dad.c = c, dad.m = m;
	if(dad.c == dad.m) return 0;
	q.push(dad);
	while(!q.empty())
	{
		dad = q.front(), q.pop();
		if(dad.m>=h-1 || dad.c>300 || flag[dad.c][dad.m] == 1) continue;
		for(int op=0; op<3; op++)
		{
			son.m = dad.m+1;
			switch(op)
			{
				case 0: son.c = dad.c-1; break;
				case 1: son.c = dad.c+1; break;
				case 2: son.c = dad.c*2; break;
			}
			if(son.c == son.m) return son.m-m;
			q.push(son);
		}
		flag[dad.c][dad.m] = 1;
	}
	return -1;
}
/**************************************/
int main()
{
	scanf("%d", &n);
	while(n--)
	{
		memset(flag,0,sizeof(flag));
		scanf("%d%d%d", &h, &c, &m);
		printf("%d\n", bfs());	
	}

	return 0;
}