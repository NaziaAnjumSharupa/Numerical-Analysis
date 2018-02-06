newton raphson
#include<iostream>
#include<math.h>
#include<conio.h>
#define E 0.0001

using namespace std;

double func(double x,double a,double b, double c)
    {
    return a*x*x+b*x+c;
    }
    double diff(double x,double a,double b)
    {
       return 2*a*x+b;
    }

int main()
{
    double x1,f,fdiff,x0,root,a,b,c,d;
    int i=1;
    cout<<"Enter a limit: ";
    cin>>x0;
    cout<<"Enter a, b and c: ";
    cin>>a>>b>>c;
    f=func(x0,a,b,c);
    fdiff=diff(x0,a,b);
    while(i<100)
    {
        x1=x0-(f/fdiff);
        cout<<endl<<"Iteration "<<i<<" "<<x1;
        if(fabs((x1-x0)/x1)<=E)
        {
            root=x0-(f/fdiff);
            cout<<endl<<"Final iteration = "<<i+1<<" Root = "<<root;
            goto stop;
        }
        else
        i++;
        x0=x1;
        f=func(x0,a,b,c);
        fdiff=diff(x0,a,b);
    }
    stop:
        return 0;
}
