#include <iostream>
#include <cstdio>
using namespace std;

int x,y;
void FindCoo(int n);
int main()
{
	FILE *p,*q,*r;
	p = fopen("D:\\outx.txt","w");
	q = fopen("D:\\outy.txt","w");
	r = fopen("D:\\out.txt","w");
	int n;
	for(n = 1;n <= 100000;n ++)
	{
		FindCoo(n);
		fprintf(p,"%d,\n",x);
		fprintf(q,"%d,\n",y);
		fprintf(r,"%d %d %d\n",n,x,y);
	}
	fclose(p);
	fclose(q);
	fclose(r);
	/*while(cin >> n)
	{
		FindCoo(n);
		cout << x <<" " << y << endl;
	}*/
	return 0;
}
void FindCoo(int n)
{
	int i,j,k;
	long int layer,num,start;
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