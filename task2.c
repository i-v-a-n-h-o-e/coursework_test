/**
 вычислить формулу x=(((a+b)*c)/(m-n))^2
 **/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b,c,m,n;

    double x;

    printf("input a ");
    scanf("%lf",&a);

    printf("input b ");
    scanf("%lf",&b);

    printf("input c ");
    scanf("%lf",&c);

    printf("input m ");
    scanf("%lf",&n);

    printf("input n ");
    scanf("%lf",&n);

    if (m != n) { //Проверка для исключения деления на 0
            x = ((a + b) * c) / (m - n);
            printf("x is %f", x * x);
    }
    else printf("error: m = n!!!");

    return 0;
}
