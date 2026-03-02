#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const int N = 5;
const int M = 5;


int main()
{
    srand(time(NULL));
    
    int i, j, A[N][M];

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            A[i][j] = rand() % 100; // Random number from 0 to 99
        }
    }
    //
    printf(" Array A[%d][%d]\n",N,M);
    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < M; j ++)
        {
            printf(" %4d ", A[i][j]);
        }
        printf("\n");
    }

    // Task 1.1
    // Знайти мінімальне і максимальне значення матриці
    int Min, Max, imin, jmin, imax, jmax;
    float Avg;
    Min = A[0][0];
    Max = A[0][0];
    for ( i = 0; i < N; i ++ )
    {
        for ( j = 0; j < M; j ++ )
        {
                if(A[i][j] <= Min)
                {
                    Min = A[i][j];
                    imin = i;
                    jmin = j;
                }
                if (A[i][j] >= Max)
                {
                    Max = A[i][j];
                    imax = i;
                    jmax = j;
                }
        }
    }
    printf("\n Task 1.1");
    printf("\n Min: A[%d][%d] = %d",imin, jmin, Min);
    printf("\n Max: A[%d][%d] = %d \n",imax, jmax, Max);

    // Task 1.2
    // Поміняти місцями мінімалне і максимальне значення матриці
    // Вивести матрицю на екран
    printf("\n Task 1.2");
    printf("\n Change the minimum and maximum values ​​of a matrix:");
    int K = A[imin][jmin];
    A[imin][jmin] = A[imax][jmax];
    A[imax][jmax] = K;
    printf("\n Array A[%d][%d] after changing Min and Max\n", N, M);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if ((i == imin && j == jmin) || (i == imax && j == jmax)) {
                printf(" %4d| ", A[i][j]);
            } else {
                printf(" %4d ", A[i][j]);
            }
        }
        printf("\n");
    }

    // Task 1.3
    //Поміняти місцями головну і побочні діагоналі матриці
    int temp;
    for (i = 0; i < N; i++) {
        temp = A[i][i];
        A[i][i] = A[i][N - 1 - i];
        A[i][N - 1 - i] = temp;
    }
    printf("\n Task 1.3");
    printf("\n Array A[%d][%d] after changing main and secondary diagonals\n", N, M);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            if (i == j || j == N - 1 - i) {
                printf(" %4d| ", A[i][j]);
            } else {
                printf(" %4d ", A[i][j]);
            }
        }
        printf("\n");
    }
    
    // Task 1.4
    // Обчислити суму елементів кожного рядка матриці
    // Знайти рядок з максимальною і мінімальною сумою
    // Поміняти місцями рядки з максимальною і мінімальною сумою
    int rowSum, minRowSum, maxRowSum, i_minRow, i_maxRow;
    minRowSum = 0;
    maxRowSum = 0;
    i_minRow = 0;
    i_maxRow = 0;

    printf("\n Sum od each row:\n");
    for (i = 0; i < N; i++) {
        rowSum = 0;
        for (j = 0; j < M; j++) {
            rowSum += A[i][j];
        }
        printf(" Sum of %d row: %d\n", i, rowSum);

        if (i == 0 || rowSum < minRowSum) {
            minRowSum = rowSum;
            i_minRow = i;
        }
        if (i == 0 || rowSum > maxRowSum) {
            maxRowSum = rowSum;
            i_maxRow = i;
        }
    }
    printf("\n Task 1.4");
    // Поміняти рядки з максимальним і мінімальною сумою
    printf("\n Change rows with maximum and minimum sums:\n");
    for (j = 0; j < M; j++) {
        int temp = A[i_minRow][j];
        A[i_minRow][j] = A[i_maxRow][j];
        A[i_maxRow][j] = temp;
    }

    printf("\n Array A[%d][%d] after changing max and min sums row\n", N, M);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (i == i_minRow || i == i_maxRow) {
                printf(" %4d| ", A[i][j]);
            } else {
                printf(" %4d ", A[i][j]);
            }
        }
        printf("\n");
    }

    // Task 1.5
    // Поміняти стовбці і строки
    int B[M][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            B[j][i] = A[i][j];
        }
    }
    printf("\n Task 1.5");
    printf("\n Array B[%d][%d] after changing rows and columns\n", M, N);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf(" %4d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
