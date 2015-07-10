#include <stdio.h>

int main()
{
	FILE *p;
	int k,i,j,m,n;
	char a[3][4];
	char c;
	int x,o,dot,countx,counto;

	p = fopen("D:\\a.txt","r");
	fscanf(p,"%d",&k);
	for(i = 1;i <= k;i ++)
	{
		x =0;
		o = 0;
		dot = 0;
		countx = 0;
		counto = 0;
		for(j = 0;j < 3;j ++)
			fscanf(p,"%s",a[j]);
		for(m= 0;m < 3;m ++)
			for(n = 0;n < 3;n ++)
				if(a[m][n] == 'x')
					x ++;
				else if(a[m][n] == 'o')
					o ++;
				else
					dot ++;
		if(o > x || x - o > 1)
		{
			printf("no\n");
			continue;
		}

		for(m= 0;m < 3;m ++)
		{
			for(n = 0;n < 3;n ++)
				if(n == 0)
					c = a[m][n];
				else if(a[m][n] != c)
					break;
				else
					;
			if(n == 3 && c == 'o')
				counto ++;
			if(n == 3 && c == 'x')
				countx ++;
		}
		for(m= 0;m < 3;m ++)
		{
			for(n = 0;n < 3;n ++)
				if(n == 0)
					c = a[n][m];
				else if(a[n][m] != c)
					break;
				else
					;
			if(n == 3 && c == 'o')
				counto ++;
			if(n == 3 && c == 'x')
				countx ++;
		}
		for(m = 0;m < 3;m ++)
			if(m == 0)
				c = a[m][m];
			else if(a[m][m] != c)
				break;
			else
				;
		if(m == 3 && c == 'o')
				counto ++;
		if(m == 3 && c == 'x')
				countx ++;
		for(m = 0;m < 3;m ++)
			if(m == 0)
				c = a[m][2 - m];
			else if(a[m][2 - m] != c)
				break;
			else
				;
		if(m == 3 && c == 'o')
				counto ++;
		if(m == 3 && c == 'x')
				countx ++;


		if((x == o &&((counto == 0 && countx > 0) ||( counto == 1 && countx >= 1)))  || ((x - o == 1)&&((counto == 0 && countx == 2 && x !=5 ) || (counto >= 1)) ) )
			printf("no\n");
		//if((counto == 1 && countx != 1) || (countx == 1 && counto != 1 && x - o == 1)||(counto == countx && o + x >= 6)|| (counto >= 2 && o != 5) || (countx >= 2 && x != 5))
		//	printf("no\n");
		else
			printf("yes\n");

	}
	return 0;
}
