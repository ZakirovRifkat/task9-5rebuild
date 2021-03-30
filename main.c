#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void gauss(int p, int n, double **mas, int *ans)
{
    int i, j;
    int imax = p, jmax = p;

    for (i = p; i < n; i++)
        for (j = p; j < n; j++)
            if (fabs(mas[imax][jmax]) < fabs(mas[i][j]))
              {
                  imax = i;
                  jmax = j;

              }

    for (j = p; j < n + 1; j++)
     {
        double t = mas[p][j];
        mas[p][j] = mas[imax][j];
        mas[imax][j] = t;
     }

    for (i = 0; i < n; i++)
     {
        double t = mas[i][p];
        mas[i][p] = mas[i][jmax];
        mas[i][jmax] = t;
     }
    i = ans[p];

    ans[p] = ans[jmax];

    ans[jmax] = i;
}


int main()
{
    setlocale(LC_ALL, "rus");
    double **mas;
    double *x;
    int i,j,p;
    int *ans;
    int n;

    printf("¬ведите кол-во неизвестных: ");
    scanf("%d", &n);

    mas = (double**) malloc(n*sizeof(double*));
    x = (double*) malloc(n*sizeof(double));
    ans = (int*) malloc(n*sizeof(int));

    for (int i = 0; i < n; ++i)
     {
        mas[i] = (double*) malloc((n+1)*sizeof(double));
     }

    printf("Ёлементы матрицы\n");
    for (i = 0; i < n; ++i)
        for (j = 0; j <= n; ++j)
        {

            printf("A[%d][%d] : ", i,j);
            scanf("%lf", &mas[i][j]);
        }



    for (i = 0; i < n; ++i)
        ans[i] = i;

    for (p = 0; p < n; ++p)
    {
        gauss(p, n, mas, ans);

        if (fabs(mas[p][p]) < 0.00001 )
         {
            printf("");
            return 0;
         }

        for (j = n; j >= p; --j)
            mas[p][j]= mas[p][j]/mas[p][p];


        for (i = p + 1; i < n; ++i)
            for (j = n; j >= p; --j)
                mas[i][j] = mas[i][j] - (mas[p][j] * mas[i][p]);

    }

    for ( i = 0; i < n; ++i)
        x[i] = mas[i][n];

    for (i = n - 2; i >= 0; --i)
        for (j = i + 1; j < n; ++j)
            x[i]= x[i] - (x[j] * mas[i][j]);

    printf("\n");

    printf("ќтвет:\n");
    for (i = 0; i < n; ++i)
        for (j = 0; j <= n; ++j)

            if (i == ans[j])
            {
                printf("x=%f\n", x[j]);
                break;
            }
    return 0;
}
