
#include<iostream>
#include<math.h>
#include<conio.h>
#define E 0.00001

using namespace std;

float squar(float x,float a,float b, float c)
    {
    return a*x*x+b*x+c;
    }

float cube(float x,float a, float b, float c, float d)
{
return a*x*x*x+b*x*x+c*x+d;
}


int main()
{
    float n,x1,x2,f0,f1,f2,x0,root,a,b,c,d;
    int i=1;
    cout<<"Enter degree of the equation: ";
    cin>>n;
    cout<<"Enter two limits: ";
    cin>>x1>>x2;
    if(n==2)
    {

    cout<<"Enter a, b and c: ";
    cin>>a>>b>>c;
    }
    else if(n==3)
    {

    cout<<"Enter a, b ,c and d: ";
    cin>>a>>b>>c>>d;
    }
    else
        cout<<"Invalid input!";
    f1=n==2?squar(x1,a,b,c):cube(x1,a,b,c,d);
    f2=n==2?squar(x2,a,b,c):cube(x2,a,b,c,d);
    if(f1*f2>0)
    {
        cout<<endl<<"x1 & x2 do not bracket any root";
        goto stop;
    }


    while(i<100)
    {
        x0=x1-f1*((x2-x1)/(f2-f1));
        f0=n==2?squar(x0,a,b,c):cube(x0,a,b,c,d);
        if(f1*f0<0)
            x2=x0;
        else
        {
            x1=x0;
        }
        cout<<endl<<"Iteration "<<i<<" "<<x1<<" "<<x2;
        if(fabs((x2-x1)/x2)<E)
        {
            root=x1-f1*((x2-x1)/(f2-f1));
            cout<<endl<<"Final iteration = "<<i+1<<" Root = "<<root;
            goto stop;
        }
        else
        i++;
    }
    stop:
        return 0;
}
