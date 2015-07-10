#include <iostream>
using namespace std;

int main()
{
	char a[1000][1000],flag;
	int i,j,k,n,m,p;
	while(cin >> n)
	{
		flag = 0;
		p = 2 * n - 1;
		m = (2 * n - 1) / 2 + 1;
		for(i = m ;i >= 1;i --)
		{
			if(flag == 0)
			{
				for(k = i;k <= p - i + 1;k ++)
					a[k][i] = a[i][k] = '*';
				k --;
				for(j = i ; j <= p - i + 1;j ++)
					a[j][k] = a[k][j] = '*';
				flag = 1;
			}
			else
			{
				for(k = i;k <= p - i + 1;k ++)
					a[k][i] = a[i][k] = '.';
				k --;
				for(j = i ; j <= p - i + 1;j ++)
					a[k][j] = a[j][k] = '.';
				flag = 0;
			}
		}
		for(i = 1;i <= p;i ++)
		{
			for(j = 1;j <=  p;j ++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
}