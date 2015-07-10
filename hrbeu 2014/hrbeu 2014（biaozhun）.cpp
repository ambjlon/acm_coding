#include <iostream>
using namespace std;

int x,y;
void FindCoo(int n);
int main()
{
	int n;
	while(cin >> n)
	{
		FindCoo(n);
		cout << x <<" " << y << endl;
	}
	return 0;
}
void FindCoo(int n)
{
	int i,j,k;
	int layer,num,start;
	if(n == 1)
	{
		x = 0;
		y = 0;
		return;
	}
	else
	{
		for(i = 1;i <= 184;i ++)
			if(n < (3*i*i - 3*i + 2))
			{
				layer = i - 1;
				break;
			}
		start = 3*layer*layer - 3*layer + 2;
		num = n - start + 1;
	    x = layer - 1;
		y = 1;
		k = 2;
		for(i = 1;i <= layer - 1;i ++)
		{
			if(k > num)
				break;
			x--;
			y++;
			k++;
		}
		for(i = 1;i <= layer ;i ++)
		{
			if(k > num)
				break;
			x--;
			k++;
		}
		for(i = 1;i <= layer ;i ++)
		{
			if(k > num)
				break;
			y--;
			k++;
		}
		for(i = 1;i <= layer ;i ++)
		{
			if(k > num)
				break;
			x++;
			y--;
			k++;
		}
		for(i = 1;i <= layer ;i ++)
		{
			if(k > num)
				break;
			x++;
			k++;
		}
		for(i = 1;i <= layer ;i ++)
		{
			if(k > num)
				break;
			y++;
			k++;
		}
	}
}