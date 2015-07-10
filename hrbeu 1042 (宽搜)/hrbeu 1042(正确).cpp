#include <iostream>
#include <string>
#include <deque>
#include <memory.h>

using namespace std;

char dungeon[40][40][40];
typedef struct qu
{
	int x,y,z;
	int mov;
}Q,*PQ;

int main()
{
	int  i,j,k,yes;
	int l,r,c;
	int dir[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{-1,0,0},{1,0,0}};
	string s;
	Q el,el1;
	deque<Q> queue;
	
	cin >> l >> r >> c;
	while(l != 0 && r != 0 && r != 0)
	{
		memset(dungeon,'#',sizeof(dungeon));
		queue.clear();
		for(i = 0;i < l;i ++)
		{
			for(j = 0;j < r;j ++)
			{
				cin >> s;
				s.copy(dungeon[i][j],s.size(),0);
			}
		}
		yes = 0;
		for(i = 0;i < l;i ++)
			for(j = 0;j < r;j ++)
				for(k = 0;k < c;k ++)
					if(dungeon[i][j][k] == 'S')
					{
						el.x = i;
						el.y = j;
						el.z = k;
						el.mov = 0;
						queue.push_back(el);
						break;
					}
					while(! queue.empty())
					{
						el = *(queue.begin());
						queue.pop_front();
						for(i = 0;i <= 5;i ++)
						{
							el1.x = el.x + dir[i][0];
							el1.y = el.y + dir[i][1];
							el1.z = el.z + dir[i][2];
							if((el1.x < 0 || el1.y < 0 || el1.z < 0) || dungeon[el1.x][el1.y][el1.z] == '#')
								continue;
							else
							{
								el1.mov = el.mov + 1;
								queue.push_back(el1);
								if(dungeon[el1.x][el1.y][el1.z] == 'E')
								{
									yes = 1;
									break;
								}
								dungeon[el1.x][el1.y][el1.z] = '#';//注意这里！！访问过就标记上？！
							}
						}
						if(yes)
							break;
					}
					if(yes)
						cout << "Escaped in " <<el1.mov<<" minute(s)."<<endl;
					else
						cout <<"Trapped!"<<endl;
					cin >> l >> r >> c;
	}
	return 0;
}