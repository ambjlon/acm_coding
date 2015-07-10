#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int m,n,i,j,k,count;
	int x,y,lmt,num,max;
	int map[201][201];
	int D[201],final[201];
	string tmpx,tmpy;
	vector<string> city;
	vector<string>::iterator itx,ity;
	count = 1;
	while(cin>>m>>n && m != 0 && n!= 0)
	{
		memset(map,0,sizeof(map));
		memset(D,0,sizeof(D));
		memset(final,0,sizeof(final));
		for(i = 1;i <= n + 1;i ++)
		{
			if(i == n + 1)
				cin >> tmpx >> tmpy;
			else
				cin >> tmpx >> tmpy >> lmt;
			itx = find(city.begin(),city.end(),tmpx);
			if(itx == city.end())
			{
				city.push_back(tmpx);
				x = city.end() - city.begin();
			}
			else
				x = itx - city.begin() + 1;
			ity = find(city.begin(),city.end(),tmpy);
			if(ity == city.end())
			{
				city.push_back(tmpy);
				y = city.end() - city.begin();
			}
			else
				y = ity - city.begin() + 1;
			if(i != n + 1)
				map[y][x] = map[x][y] = lmt;
		}
		num = city.size();
		//Dijstra
		final[x] = 1;
		for(i = 1;i <= num;i ++)
			D[i] = map[x][i];
		for(i = 1;i <= num - 1;i ++)
		{
			max = -1;
			for(j = 1;j <= num;j ++)
				if(final[j] == 0 && D[j] > max)
				{
					max = D[j];
					k = j;
				}
			final[k] = 1;
			for(j = 1;j <= num;j ++)
				if(final[j] == 0 && (D[k] > map[k][j] ? map[k][j] : D[k]) > D[j])
					D[j] = (D[k] > map[k][j] ? map[k][j] : D[k]);
		}
		cout << "Scenario #" << count << endl;
		cout << D[y] << " tons" << endl << endl;
		count ++;
	}
	return 0;
}