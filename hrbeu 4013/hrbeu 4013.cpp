#include <iostream>
#include <string>
#include <memory.h>
#include <map>

using namespace std;

int main()
{
	int i,j,n,p,k,m,s,e,max;
	int power[40000];
	string sc;
	multimap<string,int> a;
	multimap<string,int>::iterator itr;

	cin>>n;
	for(i = 0;i < n;i ++)
	{
		cin>>sc>>p;
		a.insert(multimap<string,int>::value_type(sc,p));
	}
	while(cin>>k>>m)
	{
		memset(power,0,sizeof(power));
		max = 0;
		for(i = 0;i < k;i ++)
		{
			cin>>sc>>s>>e;
			itr = a.find(sc);
			for(j = s;j <= e;j ++)
				power[j] += (*itr).second;
		}
		for(i = 0;i <= 32768;i ++)
			if(power[i] > m)
				break;
			else
			{
				if(power[i] > max)
					max = power[i];
			}
		if(i <= 32768)
		{
			if(power[i] > 1)
			    cout<<"The power will be out at time "<<i<<" because the power is "<<power[i]<<" Watts and overloaded."<<endl;
			else
				cout<<"The power will be out at time "<<i<<" because the power is "<<power[i]<<" Watt and overloaded."<<endl;
		}
		else
		{
			if(max <= 1)
				cout<<"The maximum power needed is "<<max<<" Watt."<<endl;
			else
				cout<<"The maximum power needed is "<<max<<" Watts."<<endl;
		}

	}
	return 0;
}