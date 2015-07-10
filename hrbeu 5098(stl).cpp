#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[202],b[20];
	int n;
	while(cin >> n)
	{
		int i;
		for(i = 1;i <= n;i ++)
			cin >> b[i];
		for(i = 1;i <= (10 * n);i ++)
			cin >> a[i];
		sort(b+1,b+n+1);
		int max,sum = 0,pl = 0;
		for(i = 1;i <= n;i ++)
			sum+=a[pl+=b[i]];
		max = sum;
		while(next_permutation(b+1,b+n+1))
		{
			sum = 0,pl = 0;
			for(i = 1;i <= n;i ++)
			sum+=a[pl+=b[i]];
		    if(max < sum)
			 max = sum;
		}
		cout << max << endl;
	}
	return 0;
}