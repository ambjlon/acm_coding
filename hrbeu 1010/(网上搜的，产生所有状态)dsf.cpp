#include<iostream>

#include<cmath>

using namespace std;


int have[60000],used[60000];

int map[3][3];

int ok(int k) 

{

    int i,j,kk=k;

    for(i=2;i>=0;i--)

       for(j=2;j>=0;j--)

       {

           map[i][j]=kk%3;

           kk=kk/3;

       }

    for(i=0;i<3;i++)

    {

       if(map[i][0]==2 && map[i][1]==2 && map[i][2]==2)

           return 0;

       if(map[0][i]==2 && map[1][i]==2 && map[2][i]==2)

           return 0;

       if(map[i][0]==1 && map[i][1]==1 && map[i][2]==1)

           return 0;

       if(map[0][i]==1 && map[1][i]==1 && map[2][i]==1)

           return 0;

    }

    if(map[0][0]==map[1][1]&& map[1][1]==map[2][2] && map[0][0]!=0)

       return 0;

    if(map[2][0]==map[1][1]&& map[1][1]==map[0][2] && map[1][1]!=0)

       return 0;

    return 1;

}

int get(int x,int y,int k,int op)

{

    int i,j,kk=k;

    for(i=2;i>=0;i--)

       for(j=2;j>=0;j--)

       {

           map[i][j]=kk%3;

           kk=kk/3;

       }

    if(map[x][y]!=0)

       return -1;

    if(op==1) map[x][y]=1;

    else map[x][y]=2;

    for(i=0,kk=0;i<3;i++)

       for(j=0;j<3;j++)

           kk=kk*3+map[i][j];

    return kk;

}

void bfs()

{

    int i,j,x,xx;

    int q[60000],head,end,f,op;

    q[0]=0;

    have[0]=1;used[0]=1;

    head=0;end=f=1;op=1;

    while(head<end)

    {

       if(f==head)

       {

           f=end;

           op=(op+1)%2;

       }

       x=q[head++];

       for(i=0;i<3;i++)

           for(j=0;j<3;j++)

           {

              xx=get(i,j,x,op);

              if(xx!=-1 && !used[xx])

              {

                  used[xx]=1;

                  have[xx]=1;

                  if(ok(xx)) //还可以放

                  {

                     q[end++]=xx;

                  }

              }

           }

    }

}

int main()

{

    int i,j,cas,n;

    bfs();

    //cout<<pow(3,10);

    scanf("%d",&cas);

    while(cas--)

    {

       int k=0;

       char s[4];

       for(i=0;i<3;i++)

       {

           scanf("%s",s);

           for(j=0;j<3;j++)

           {

              k=k*3;

              if(s[j]=='X')

                  k+=1;

              if(s[j]=='O')

                  k+=2;

           }

       }

       if(have[k])

           printf("yes\n");

       else

           printf("no\n");

    }

    return 0;

}

