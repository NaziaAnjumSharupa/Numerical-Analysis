#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x)(a*x*x)+(b*x)+c
#define E 0.000001
main()
{
float root,x0,x1,x2,f0,f1,f2;
int i=1,a,b,c;
printf("Enter a,b,c for the equation: ");
for(i=0;i<3;i++)
{
    scanf("%d%d%d",&a,&b,&c);
}
printf("Enter two limits ");
scanf("%f%f",&x1,&x2);
f1=f(x1);
f2=f(x2);
if (f1*f2>0)
{
    printf("\nx1 & x2 do not bracket any root ");
    goto stop;
}
while(i<100)
{
    x0=x1-f(x1)*((x2-x1)/(f(x2)-f(x1)));
    f0=f(x0);
    if(f1*f0<0)
    {
        x2=x0;
    }
    else{
        x1=x0;
        f1=f0;
    }
    printf("\nIteration %d %f %f",i,x1,x2);
    if(fabs((x2-x1)/x2))
    {
        root=(x1-x2)/2;
        printf("\nfinal iteration root=%f",i+1,root);
        goto stop;
    }
    else
        i++;

}
stop;
getch();
}
