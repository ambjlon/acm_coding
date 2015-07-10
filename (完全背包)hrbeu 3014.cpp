#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	int i,j,k;
	int value[501],weight[501],c[10002];
	int t,n;
	int net,e,f;

	cin >> t;
	for(i = 0;i < t;i ++)
	{
		memset(value,0,sizeof(value));
		memset(weight,0,sizeof(weight));
		memset(c,-1,sizeof(c));
		c[0] = 0;
		cin >> e >> f;
		net = f - e;//net weight x.

		cin >> n;
		for(j = 0;j < n;j ++)
			cin >> value[j] >> weight[j];
		for(k = 0;k < n;k ++)
		{
			for(j = weight[k];j <= net;j ++)
				if(c[j] == -1 && c[j - weight[k]] == -1)
					c[j] = -1;
				else if(c[j] != -1 && c[j - weight[k]] == -1)
					;
				else if(c[j] == -1 && c[j - weight[k]] != -1)
					c[j] = c[j - weight[k]] + value[k];
				else
					c[j] = (c[j - weight[k]] + value[k] < c[j] ? c[j - weight[k]] + value[k] : c[j]);
		}
		if(c[net] == -1)
			cout << "This is impossible."<<endl;
		else
			cout << "The minimum amount of money in the piggy-bank is "<< c[net]<<"."<<endl;
	}
	return 0;
}