#include <stdio.h>

int main()
{
	int i;
	int n,mys,myj,myb,ops,opj,opb,count;
	char x[101];

	scanf("%d",&n);
	getchar();
	while(n != 0)
	{
		for(i = 0;i < n;i ++)
			scanf("%c",&x[i]);
		scanf("%d%d%d",&mys,&myj,&myb);
		ops = opj = opb = 0;
		count = 0;
		for(i = 0;i < n;i ++)
			if(x[i] == 'S')
				ops ++;
			else if(x[i] == 'J')
				opj ++;
			else
				opb ++; 
		if(ops <= myb)
		{
			count += ops;
			myb = myb - ops;
			ops = 0;
		}
		else
		{
			count += myb;
			ops = ops - myb;
			myb = 0;
		}
		if(opj <= mys)
		{
			count += opj;
			mys = mys - opj;
			opj = 0;
		}
		else
		{
			count += mys;
			opj = opj - mys;
			mys = 0;
		}
		if(opb <= myj)
		{
			count += opb;
			myj = myj - opb;
			opb = 0;
		}
		else
		{
			count += myj;
			opb = opb - myj;
			myj = 0;
		}
		if(ops <= mys)
		{
			mys = mys - ops;
			ops = 0;
		}
		else
		{
			ops = ops - mys;
			mys = 0;
		}
		if(opj <= myj)
		{
			myj = myj - opj;
			opj = 0;
		}
		else
		{
			opj = opj - myj;
			myj = 0;
		}
		if(opb <= myb)
		{
			myb = myb - opb;
			opb = 0;
		}
		else
		{
			opb = opb - myb;
			myb = 0;
		}
		count = count - mys - myj - myb;
		printf("%d\n",count);

		scanf("%d",&n);
	    getchar();
	}
	return 0;
}