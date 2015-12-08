/**
 *
 * Протабулировать функцию
 * y=(sin(x)+cos^2(x))/(sin(x^2)-3*tan(x/5));
 * на интервале 2..11 с шагом 1.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
   return (sin(x) + cos(x) * cos(x)) / (sin(x * x) - 3. * tan( x / 5.));
}

int main()
{
    int i;
    for (i = 2; i < 12; i++)
           printf("y(%d) = %f \n", i, f(i));
    return 0;
}
