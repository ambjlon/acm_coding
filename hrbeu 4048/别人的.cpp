#include<iostream>

using namespace std;

typedef long long int64;

int64 dp[ 51 ][ 51 ];

int a[ 55 ],b[ 55 ];

int main()

{

  int n,k;

  int64 tp;

  double sum;

  dp[ 0 ][ 0 ] = 1;

  dp[ 1 ][ 0 ] = dp[ 1 ][ 1 ] = 1;

  for(int i=2;i<=50;i++)

      for(int j=0;j<=i;j++)

      {

         if( j )dp[i][j] = dp[i-1][j-1] + dp[ i-1 ][j];

         else dp[i][0] = 1;

      }

  while( scanf("%d%d",&n,&k) && n != -1 )

  {

    tp = 0;

    for(int i=0;i<n;i++)

    { 

      scanf("%d",&a[i]);

      tp += a[i];

    }

    for(int i=0;i<n;i++)

    {

       scanf("%d",&b[i]);

    }

    sum = dp[ tp ][ k ];

    tp = 1;

    for(int i=0;i<n;i++)

    {

        tp *= dp[ a[i]  ][  b[i] ];

    }

    printf("%.5lf\n",tp/sum);

  }

}
