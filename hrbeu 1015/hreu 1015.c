#include <stdio.h>

int flag[10000][10000];//为了减少不必要的重复搜索，记录已经得到的信息
int JudWin(int min,int max);
int main()
{
	int i,j;
	int a,b;

	FILE *fp;
	FILE *fq;
	fp=fopen("D:\\in.txt","r");
	fq=fopen("D:\\wd.txt","w");

	for(i=0;i<10000;i++)
		for(j=0;j<10000;j++)
			flag[i][j]=-1;


	fscanf(fp,"%d %d",&a,&b);
	while(a!=0||b!=0)
	{
		if(a<=b)
		{
			if(JudWin(a,b))
				fprintf(fq,"%s","Stan wins\n");
			else
				fprintf(fq,"%s","Ollie wins\n");
		}
	    else
		{
			if(JudWin(b,a))
				fprintf(fq,"%s","Stan wins\n");
			else
				fprintf(fq,"%s","Stan wins\n");
		}
		fscanf(fp,"%d%d",&a,&b);
	}
	return 0;
}

//递归
int JudWin(int min,int max)
{
	if(flag[min][max]==1)
		return 1;
	if(flag[min][max]==0)
		return 0;
	if((min!=0&&max%min==0)||min==0)
		return 1;
	else
	{
	    int i,l,g,t;
		t=max;
	    for(i=min;i<=t;i=i+min)
		{
			max=t-i;
			if(min<=max)
			{
				l=min;
				g=max;
			}
			else
			{
				l=max;
				g=min;
			}
		     if(!JudWin(l,g))
			 {
				 flag[min][t]=1;
				 return 1;
			 }
		}
		flag[min][t]=0;
		return 0;
	}
}