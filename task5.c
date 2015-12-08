#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,p,s = 0,s1 = 0,t;

    for (k = 1;k < 11; k++) {
        s1 = 0;
        for (p = 1; p < 16; p++)
            t = (k - p);
            s1 += t * t;
        s += k * k * k * s1;
    }
    printf("%d", s);
}

