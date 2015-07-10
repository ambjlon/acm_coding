#include<iostream.h> 
#include<fstream.h> 
#include<stdlib.h> 
#include<algorithm> 
#include<time.h> 

//ofstream out("out"); 
//ifstream in("in"); 
//ifstream in("test.java"); 
//#define cin in 
//#define cout out 

int data[100];//data input 
int save[100];// data fill 
int thx;//how many hole 
int thy;//number input 
int total;//total of input 
int max;//max number 
int length;//hole depth 
int v[100]; 
int vk;//number of factor 
int fill[10000]; 
//int datain[200]; 

long now; 
int ttt; 

void input()
{ 
    int i; 
    cin>>i; 
    //cout<<i<<endl;/// 
    //cout<<++ttt<<endl;/// 
    if(i==0){ 
        //cout<<"time cost:"<<(clock()-now)/1000.0<<endl; 
        exit(0);  } 
now=clock();///// 

    thy=i; 
    int j; 
    max=0; 
    total=0; 
    //for(j=1;j<200;j++) 
    //    datain[j]=0; 
    int kk=0; 
    for(j=0;j<i;j++){ 
        int temp; 
        cin>>temp; 
        if(temp>50){ 
            thy--; 
            continue; 
        } 
        data[kk]=temp; 
        total+=data[kk]; 
        //datain[data[kk]]++; 
        if(data[kk]>max) 
            max=data[kk]; 
        kk++; 
    } 
    if(thy==0)return; 
    std::sort(data,data+thy); 
    std::reverse(data,data+thy); 
    for(i=1;i<total;i++) 
        fill[i]=0; 
    fill[0]=1; 
    int tmax=0; 
    for(i=0;i<thy;i++){ 
        for(j=tmax;j>=0;j--) 
            if(fill[j]==1)fill[j+data[i]]=1; 
        tmax+=data[i]; 
    } 
    //cout<<"total:"<<total<<endl;/// 
} 


void factor(){ 
    int i; 
    vk=0; 
    for(i=max;i<=total;i++) 
        if(total%i==0) 
            v[vk++]=i; 
} 


void clear(){ 
    int i; 
    for(i=0;i<thx;i++) 
        save[i]=0; 
} 


bool solve(int k){ 
    if(k==thy) 
        return true; 
    if(clock()-now>0)/// 
        return true;/// 
    int i; 
    bool judge=false; 
    for(i=0;i<thx;i++)//// 
        if(save[i]+data[k]==length){/// 
            save[i]=length;/// 
            bool t=solve(k+1);/// 
            save[i]-=data[k]; 
            return t; 
        }/// 
    for(i=0;i<thx;i++){ 
        if(fill[length-save[i]]==0) 
            return false; 
        if(save[i]+data[k]<=length){ 
            if(save[i]==0){ 
                if(judge==false)judge=true; 
                else break; 
            } 
            save[i]+=data[k]; 
            if(solve(k+1)==true)return true; 
            save[i]-=data[k]; 
        } 
    } 
    return false; 
} 

/*inline bool solveanother(){ 
    if(datain[1]<datain[length-1]) 
        return false; 
    int a=datain[1]-datain[length-1]; 
    if(length>4){ 
        if(datain[2]+a/2<datain[length-2]) 
            return false; 
    } 
    if(length>6){ 
        int b; 
        if(datain[2]>datain[length-2]){ 
            b=datain[2]-datain[length-2]; 
        } 
        else{ 
            b=0; 
            a-=2*(datain[length-2]-datain[2]); 
        } 
        if(a>=b){ 
            if(datain[3]+(a+2*b)/3<datain[length-3]) 
                return false; 
        } 
        else{ 
            if(datain[3]+a<datain[length-3]) 
                return false; 
        } 
    } 
    return true; 
}*/ 

void main(){ 
    while(1){ 
        input(); 
        if(thy==0){ 
            cout<<0<<endl; 
            continue; 
        } 
        factor(); 
        int i=0; 
        bool judge=false; 
        ///now=clock();///// 
        while(i!=vk-1){ 
            length=v[i++]; 
            //cout<<"length:"<<length<<endl;/// 
            //int j; 
            //if(!solveanother()) 
            //    goto end; 
            //for(j=0;j!=total;j+=length)// 
            //    if(fill[j]==0)// 
            //        goto end;// 
            thx=total/length; 
            clear(); 
            if(solve(0)){ 
                judge=true; 
                cout<<length<<endl; 
                break; 
            } 
        //end:; 
        } 
        if(!judge){ 
            cout<<total<<endl; 
        } 
        //++ttt; 
        //long then; 
        //if((then=clock()-now)>10) 
        //    cout<<"line:"<<ttt<<"time:"<<then<<endl; 
    } 
} 


