#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100][100]; /**< Исходная матрица */
    int s[100], index[100];/**< Матрица сумм  и индексов */

    unsigned int n,i,j,t;

    FILE *f = fopen("input.txt", "r");

    fscanf(f,"%u", &n);

    //printf("input size of matrix ");

    //printf("input elements of matrix \n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f,"%d", &a[i][j]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }  // Вывод введенной матрицы

    for (i = 0; i < n; i++) {
        s[i] = 0;
        for (j = 0; j < n; j++)
            if ((a[i][j] > 0)&&(a[i][j] % 2 == 0))
                s[i] += a[i][j];
       // printf("%d %d \n", i ,s[i]);
     }

    printf("\n \n");

    for (i = 0; i < n; i++) index[i] = i;

    int flag = 1;

    do {
       flag = 1;
       for (i = 0; i < n - 1; i++)
          if (s[i]<s[i+1]) {
             t = s[i];
             s[i] = s[i+1];
             s[i+1] = t;
             t = index[i];
             index[i] = index[i + 1];
             index[i + 1] = t;
             flag = 0;
          }
    } while (flag);


   //for (i = 0; i < n; i ++)
   //     printf("%d %d %d \n",i, index[i], s[i]);

   //printf("\n \n");

   for (i = 0; i < n; i ++)
       if (s[i] != -1) {
           for (j = 0; j < n; j ++){
              t = a[i][j];
              a[i][j] = a[index[i]][j];
              a[index[i]][j] = t;
           }
           s[index[i]]=-1;
           s[i]=-1;
       }

   for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
   }

   return 0;
}
