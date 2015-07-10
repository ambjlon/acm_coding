#include <iostream>
#include <algorithm>

using namespace std;
typedef  struct aa
{
	int a;
	int b;
}A;
bool predicate(A x,A y);

int main()
{
	int n;
	A s[102];
	while(cin>>n)
	{
		int i,times = 0 , xx = 100;
		
		for(i = 1;i <=n ;i ++)
		{
			cin >> s[i].a >> s[i].b;
		}
		sort(s+1,s+n+1,predicate);
		for(i = 1;i <= n;i ++)
		{
			if(s[i].a <= 100)
			{
			xx = xx - s[i].b;
			times ++;
			if(xx <= 0)
				break;
			}
		}
		if(xx > 0)//²ÙÄãÂèµÄ£¡£¡£¡£¡£¡£¡²Ù¡£¡£¡£
			times = times + xx;
		cout << times << endl;
	}
	return 0;
}
bool predicate(A x,A y)
{
	if(x.b > y.b)
		return true;
	else
		return false;
}

