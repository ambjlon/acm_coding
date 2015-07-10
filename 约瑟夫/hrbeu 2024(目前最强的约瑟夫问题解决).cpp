#include <iostream>
using namespace std;
typedef  long long   int  LL;

LL  Jue(LL tp);
int main()
{
	LL  m,n;
	while(cin >> m >> n)
	{
		LL  i,rs,tmp;
		rs = m;
		for(i = 0;i < n;i ++)
		{
			tmp = rs;
			rs = Jue(rs);
			if(rs == tmp)
				break;
		}
		cout << rs << endl;
	}
	return 0;
}
LL  Jue(LL tp)
{
	if(tp == 1)
		return 1;
	else
	{
		if(tp % 2 == 0)
			return 2*Jue(tp / 2) - 1;
		else
			return 2*Jue(tp / 2 ) + 1;
	}
}