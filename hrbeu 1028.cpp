#include <iostream>
#include <string>
using namespace std;

int main()
{
	int low,high,now;
	char b[100];
	string a,t;
	
	low = 1;
	high = 10;
	while(cin >> now && now != 0)
	{
		getchar();
		cin.getline(b,'\n');
		
		a = b;
		if(a == "right on")
		{
			
			if(now <= high && now >= low)
			cout << "Stan may be honest" << endl;
			else
			cout << "Stan is dishonest" << endl;
			low = 1;
			high = 10;
			continue;
		}
		else if(a == "too low")
		{
			if(low <= now && now < high)
				low = now + 1;
			else if(now >= high)
			{
				cout << "Stan is dishonest" << endl;
				while(cin.getline(b,'\n'))
				{
					t = b;
					if(t == "right on")
						break;
				}
				low = 1;
			high = 10;
				continue;
			}
			else
				;
		}
		else
		{
			if(low < now && now <= high)
				high = now - 1;
			else if(now <= low)
			{
				cout << "Stan is dishonest" << endl;
				while(cin.getline(b,'\n'))
				{
					t = b;
					if(t == "right on")
						break;
				}
				low = 1;
			high = 10;
				continue;
			}
			else
				;
		}
	}
	return 0;
}
