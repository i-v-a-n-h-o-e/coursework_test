/// Вычислить объем усеченного конуса по формуле h * M_PI * (r1 * r1 + r1 * r2 + r2 * r2) / 3.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double h, r1, r2;
    printf("input height ");
    scanf("%lf",&h);
    if (h < 0) { // Проверка положительности высоты конуса
        printf("Error: h=0");
        return 0;
    }

    printf("input radiuses ");
    scanf("%lf %lf",&r1, &r2);

    if ((r1 < 0)||(r2 < 0)) {// Проверка положительности радиусов оснований конуса
        printf("Error: radius < 0");
        return 0;
    }

    printf("volume of truncated con is %f ", h * M_PI * (r1 * r1 + r1 * r2 + r2 * r2) / 3.);
    getch();
    return 0;
}

