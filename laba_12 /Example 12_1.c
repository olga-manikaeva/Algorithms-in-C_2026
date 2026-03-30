#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Input(int *ptrN, int *ptrM);

int main()
{
    int N, M;
    Input(&N, &M);

    int K = N * M;
    int *Array = (int*)malloc(K * sizeof(int));
    if (Array == NULL)
    {
        printf("Memory not allocated\n");
        return 1;
    }

    int *f_array = Array;
    int *l_array = Array + K;
    int *n_array;

    // Заповнення масиву випадковими числами від -50 до +50
    srand(time(NULL));
    for (n_array = f_array; n_array < l_array; n_array++)
    {
        *n_array = (rand() % 101) - 50;
    }

    // Вивід як звичайної матриці
    printf("\nMatrix:\n");

    int *row_ptr;  // вказівник на початок кожного рядка
    int *col_ptr;  // вказівник на поточний елемент у рядку

    for (row_ptr = f_array; row_ptr < l_array; row_ptr += M)
    {
        for (col_ptr = row_ptr; col_ptr < row_ptr + M; col_ptr++)
        {
            printf("%5d", *col_ptr);
        }
        printf("\n");
    }

    // Вивід кожного рядка у зворотному порядку через подвійний цикл
    printf("\nEach row in reverse order (with row & column pointers):\n");

    for (row_ptr = f_array; row_ptr < l_array; row_ptr += M)
    {
        for (col_ptr = row_ptr + M - 1; col_ptr >= row_ptr; col_ptr--)
        {
            printf("%5d", *col_ptr);
        }
        printf("\n");
    }

    free(Array);
    return 0;
}

// Функція для введення розмірів матриці
void Input(int *ptrN, int *ptrM)
{
    printf("Enter number of rows: ");
    scanf("%d", ptrN);
    printf("Enter number of columns: ");
    scanf("%d", ptrM);
}
