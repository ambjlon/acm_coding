#include <iostream>
#include <memory.h>
using namespace std;

int f[33][33];
int main()
{
	int i,j,k,n,x,y,count;
	char c;
	cin >> n;
	count = 1;
	for(k = 0;k < n;k ++)
	{
		memset(f,0,sizeof(f));
		cin >> x >> y;
		//x = x - 1;
		while(cin >> c && c != '.')
		{
			switch (c)
			{
			case 'N':
				f[x + 1][y + 1] = 1;
				y = y + 1;
				break;
			case 'S':
			    f[x][y] = 1;
				y = y - 1;
				break;
			case 'W':
				f[x][y + 1] = 1;
				x = x - 1;
				break;
			case 'E':
			    f[x + 1][y] = 1;
				x = x + 1;
				break;
			}
		}
		cout << "Bitmap #" << count ++ << endl;
    	//cout << endl;
		for(i = 32;i >= 1;i --)
		{
			for(j = 1;j <= 32;j ++)
				if(f[j][i] == 1)
					cout << 'X';
				else
					cout << '.';
        	cout << endl;
			//cout << endl;
		}
		cout << endl;
	}
	return 0;
}