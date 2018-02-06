
#include<conio.h>
#include<math.h>
#include<stdio.h>
#define ESP 0.0001
#define X1(x2,x3) ((5 - (x2) - (x3))/2)
#define X2(x1,x3) ((15 - 3*(x1) - 2*(x3))/5)
#define X3(x1,x2) ((8 - 2*(x1) - (x2))/4)

int main()
{
  double x1=0,x2=0,x3=0,y1,y2,y3;
  int i=0;
printf("\tx1\tx2\tx3",x1,x2,x3);

  do
  {
   y1=X1(x2,x3);
   y2=X2(y1,x3);
   y3=X3(y1,y2);
   if(fabs(y1-x1)<ESP && fabs(y2-x2)<ESP && fabs(y3-x3)<ESP )
   {
     printf("\n\nx1 = %.3lf",y1);
     printf("\n\nx2 = %.3lf",y2);
     printf("\n\nx3 = %.3lf",y3);
     i = 1;
   }
   else
   {
     x1 = y1;
     x2 = y2;
     x3 = y3;
     printf("\n%f\t%f\t%f",x1,x2,x3);
   }
  }while(i != 1);
getch();
return 0;
}

