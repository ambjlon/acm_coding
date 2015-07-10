#include <stdio.h>
#include <memory.h>
#include <math.h>

const double ct = sqrt(2) / 2;
char s[300],t[5];
int dirt[8];//0 N,1 NE,2 E,3 SE,4 S,5 SW,6 W,7 NW
double ax[8] = {0,ct,1,ct,0,-ct,-1,-ct};
double ay[8] = {1,ct,0,-ct,-1,-ct,0,ct};
int main()
{
	double x,y;
	int i,j,k,tm,count;
	char c,a;
	count = 1;
	while(1)
	{
		scanf("%s",s);
		if(s[0] == 'E')
			break;
		else
		{
			x = 0;
			y = 0;
			memset(dirt,0,sizeof(dirt));
			memset(t,0,sizeof(t));
			k = 0;
			for(i = 0; ;i ++)
			{
				if(s[i] == ',' || s[i] == '.')
				{
					tm = 0;
					for(j = 0;t[j] >= '0' && t[j] <= '9';j ++)
						tm = tm * 10 + t[j] - '0';
					c = t[j];
					a = t[j + 1];
					switch (c)
					{
					case 'N':
						if(a == 0)
							dirt[0] += tm;
						else
						{
							if(a == 'W')
								dirt[7] += tm;
							else
								dirt[1] += tm;
						}
						break;
					case 'E':
						dirt[2] += tm;
						break;
					case 'W':
						dirt[6] += tm;
						break;
					case 'S':
						if(a == 0)
							dirt[4] += tm;
						else
						{
							if(a == 'E')
								dirt[3] += tm;
							else
								dirt[5] += tm;
						}
						break;
					}
					if(s[i] == '.')
						break;
					memset(t,0,sizeof(t));
					k = 0;
				}
				else
					t[k ++] = s[i];
			}
			k = dirt[2] > dirt[6] ? (dirt[2] - dirt[6]):(dirt[6] - dirt[2]);
			if(dirt[2] > dirt[6])
			{
				dirt[2] = k;
				dirt[6] = 0;
			}
			else
			{
				dirt[6] = k;
				dirt[2] = 0;
			}
			k = dirt[1] > dirt[5] ? (dirt[1] - dirt[5]):(dirt[5] - dirt[1]);
			if(dirt[1] > dirt[5])
			{
				dirt[1] = k;
				dirt[5] = 0;
			}
			else
			{
				dirt[5] = k;
				dirt[1] = 0;
			}
			k = dirt[3] > dirt[7] ? (dirt[3] - dirt[7]):(dirt[7] - dirt[3]);
			if(dirt[3] > dirt[7])
			{
				dirt[3] = k;
				dirt[7] = 0;
			}
			else
			{
				dirt[7] = k;
				dirt[3] = 0;
			}
		}
		for(i = 0;i < 8;i ++)
		{
			x = x + dirt[i] * ax[i];
			y = y + dirt[i] * ay[i];
		}
		printf("Map #%d\n",count++);
		printf("The treasure is located at (%.3lf,%.3f).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n",sqrt(x * x + y * y));
		printf("\n");
	}
    return 0;
}