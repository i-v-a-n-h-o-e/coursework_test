#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   double x,e,y = 1,d = 1;
   int i = 2;
   printf("input x: ");
   scanf("%lf",&x);
   printf("input accuracy: ");
   scanf("%lf",&e);

   do {
      d = d * x * x / (i * (i - 1));
      y += d;
      i += 2;
   } while (d > e);


   printf("%f %f",y, cosh(x));

   return 0;
}
