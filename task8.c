#include <stdio.h>
#include <stdlib.h>
#define size 100 // Константа максимального размера матрицы
void mout(double a[size][size], int n, int m) {
   int i,j;
   for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
         printf("%f ",a[i][j]);
      printf("\n");
   }
   return;
}

void matout(double a[100][100], int n) {
   int i,j;
   for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%lf ", a[i][j]);
        printf("\n");
    }
    return 0;
}
void matin(double a[], int n) {
  int i,j;
  for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &a[i*n+j]);
  return;
}
void matx(double c[100][100],double a[100][100], double b[100][100], int m, int n, int q) {
   /** Процедура предназначенная для перемножения двух матриц с элементами типа double
    *
    * Параметры процедуры: С[m x q] - результат
    * A[m x n], B[n x q] - множители
    * Размеры матриц m,n,q.
    *
    */
   int i,j,r;
   for (i = 0; i < m; i++)
      for (j = 0; j < q; j++) {
         c[i][j]=0.;
         for (r = 0; r < n; r++)
             c[i][j] += a[i][r] * b[r][j];
   }
   return;
}

void matxk(double b[100][100], double a[100][100], int n, int m, double k) {
   int i,j;
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
          b[i][j] = k * a[i][j];
   return;
}
void matdiff(double c[100][100],double a[100][100],double b[100][100],  int n, int m) {
   int i,j;
   for (i = 0; i < n; i++)
      for (j = 0; j< n; j++)
         c[i][j] = a[i][j] - b[i][j];
   return;
}
int main()
{
    unsigned int n,m,n1,i,j,t,k;
    double a[100][100],b[100][100],c[100][100];/// Основная матрица, которая вводится из файла
    double U[100][1],V[100][1], a_pr[100][100];
    double VA[1][100],VAU[1][1],AU[100][1];
    double r[100][1], q[1][100],B[100][100],C[100][100];
    double ak;

    FILE *f = fopen("input.txt", "r");

    fscanf(f,"%u",&n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            fscanf(f,"%lf", &a[i][j]);
            b[i][j] = a[i][j];
        }
    printf("initial matrix \n \n");
    matout(a,n);
    fclose(f);
/** Конец блока ввода

 *
 * В матрице A  находится обращаемая матрица
 * В матрице B ее копия, необходимая
 * для проверки корректности операции.
 *
 */
    a[0][0] = 1. / a[0][0];

    for (k = 1;k < n; k++) {
        for (i = 0; i < k; i++) {
            V[0][i] = a[k][i];
            U[i][0] = a[i][k];
            for (j = 0; j < k; j++)
                a_pr[i][j] = a[i][j];
        }
        printf("k=%d\n",k);

        printf("V: \n");
        mout(V,1,k);

        printf("U \n");
        mout(U,k,1);

        printf("a_pr \n");
        mout(a_pr,k,k);

        matx(VA, V, a_pr, 1, k, k);
        printf("VA \n");
        mout(VA,1,k);

        matx(VAU, VA, U, 1, k, 1);
        printf("VAU \n");
        mout(VAU,1,1);

        matx(AU, a_pr, U, k, k, 1);
        printf("AU \n");
        mout(AU,k,1);

        ak = a[k][k] - VAU[0][0];
        printf("ak = %f \n",ak );

        if (ak == 0) {
            printf("Sorry, but it is impossible to inverse this matrix");
            return 0;
        }
        ak = 1. / ak;
        a[k][k] = ak;
        ak *= -1.;

        matxk(r,AU,k,1,ak);
        printf("r \n");
        mout(r,k,1);

        matxk(q,VA,1,k,ak);
        printf("q \n");
        mout(q,1,k);

        matx(C,AU,q,k,1,k);
        matdiff(B,a_pr,C,k,k);

        printf("B \n");
        mout(B,k,k);

        for (i = 0; i < k; i++) {
            a[k][i]=q[0][i];
            a[i][k]=r[i][0];
            for (j = 0; j < k; j++)
                a[i][j] = B[i][j];
        }
        printf("a \n");
        mout(a,k+1,k+1);
    }
    printf("inverse matrix \n \n");
    matout(a,n);

    matx(c,a,b,n,n,n);

    printf("Correctly? \n \n");
    matout(c,n);

    return 0;
}

