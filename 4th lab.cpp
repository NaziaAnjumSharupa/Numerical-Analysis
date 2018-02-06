#include<iostream>
#include<math.h>
#include<conio.h>
#define E 0.0001

using namespace std;
float func(float x,float a,float b, float c)
    {
    return a*x*x+b*x+c;
    }
int main()
{
    float x1,x2,f1,f2,x3,root,a,b,c;
    int i=1;
    cout<<"Enter two limits: ";
    cin>>x1>>x2;
    cout<<"Enter a, b and c: ";
    cin>>a>>b>>c;
    f1=func(x1,a,b,c);
    f2=func(x2,a,b,c);
    while(i<100)
    {
        x3=((f2*x1)-(f1*x2))/(f2-f1);
        if(fabs((x3-x2)/x3)>E)
        {
            x1=x2;
            f1=f2;
            x2=x3;
            f2=func(x3,a,b,c);
            cout<<endl<<"Iteration "<<i<<" = "<<x3;
            i++;
        }
        else
        {
        root=((f2*x1)-(f1*x2))/(f2-f1);
        cout<<endl<<"Final iteration = "<<i<<" Root = "<<root;
            goto stop;
        }
    }
    stop:
        return 0;
}
