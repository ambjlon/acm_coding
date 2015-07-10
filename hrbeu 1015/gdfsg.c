#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	long t;
	long a,b;
	FILE *fp;
	FILE *fq;
	fp=fopen("D:\\in.txt","r");
	fq=fopen("D:\\hj.txt","w");

while(1)
{
       
       fscanf(fp,"%ld %ld",&a,&b);
       if(!a&&!b) 
		   break;
       
       if(a<b) t=a,a=b,b=t;
       
       if(a*1.0/b>(sqrt(5)-1)/2+1||a==b )
             fprintf(fq,"%s","Stan wins\n");
          else
             fprintf(fq,"%s","Ollie wins\n");
 }
    //system("pause");

fclose(fp);
fclose(fq);
    return 0;
}