#include<iostream>
#include<conio.h>
using namespace std;
int a,b,u,v,n,i,j,k,t,ne=1;
int visited[10]={0},mini,mincost=0,cost[10][10];
int check(int s[],int p);
Job_Sequencing()
{
    cout<<"Enter the number of jobs: ";
    cin>>n;
    int slot[n],profit,p[n],d[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter the profit of job# "<<i+1<<" : ";
        cin>>p[i];
        cout<<"Enter the deadline of job #"<<i+1<<" : ";
        cin>>d[i];
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(p[i]<p[j])
            {
                t=p[i];
                p[i]=p[j];
                p[j]=t;
                t=d[i];
                d[i]=d[j];
                d[j]=t;
            }
    for(i=0;i<n;i++)
         slot[i]=0;
    for(i=0;i<n;i++)
        for(j=d[i];j>0;j--)
            {
            if(check(slot,j)==1)
            {
                slot[i]=j;
                break;
            }
            }
    cout<<endl<<endl<<"INDEX  PROFIT  DEADLINE  SLOT ALLOTTED"<<endl;
    int os=0;
    for(i=0;i<n;i++)
    {
        if(slot[i]>0)
        {
            cout<<endl<<endl<<i+1<<"     "<<p[i]<<"     "<<d[i]<<"     "<<(slot[i]-1)<<" - "<<slot[i];
            os=os+p[i];
        }
        else
            cout<<endl<<endl<<i+1<<"   "<<p[i]<<"   "<<d[i]<<"  REJECTED!"<<endl;
    }
    cout<<endl<<endl<<"Optimal solution is: "<<os<<endl;
}
prims()
{
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the adjacency matrix :"<<endl;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        cin>>cost[i][j];
    if(cost[i][j]==0)
        cost[i][j]=999;
    }
    visited[1]=1;
    cout<<endl;
    while(ne<n)
    {
        for(i=1,mini=999;i<=n;i++)
            for(j=1;j<=n;j++)
            if(cost[i][j]<mini)
            if(visited[i]!=0)
        {
            mini=cost[i][j];
            a=u=i;
            b=v=j;
        }
        if(visited[u]==0||visited[v]==0)
        {
            cout<<endl<<"Edge "<<ne++<<": ("<<a<<" "<<b<<") Cost: "<<mini;
            mincost+=mini;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout<<endl<<"Minimum cost: "<<mincost;
}
int check(int s[],int p)
 {
     int ptr=0;
           for(int i=0;i<n;i++)
           {
               if(s[i]==p)
               ptr++;
           }
            if(ptr==0)
            return 1;
            else
            return 0;
  }
int main()
{
    int choice;
    cout<<"Enter your choice: "<<endl<<"1. Job Sequencing"<<endl<<"2. Prims Algorithm"<<endl;
    cin>>choice;
    switch(choice)
    {
case 1:
    Job_Sequencing();
    break;
case 2:
    prims();
    break;
default:
    cout<<"Invalid choice!"<<endl;
    }
    return 0;
}

