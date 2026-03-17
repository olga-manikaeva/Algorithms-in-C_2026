#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N;
    printf("Enter the array size: ");
    scanf("%d", &N);
    
    int *Array = (int*)malloc(N * sizeof(int));
    if(Array == NULL){
        printf("Memory not allocated");
        return 1;
    }
    int *n_array; // вказвник на поточний елемент
    int *f_array; // вказівник на перший елемент масиву
    int *l_array; // вказівник на останній елемент масив

    f_array = &Array[0];
    l_array = Array + N;

    // Заповнення масиву
    srand(time(NULL));
    for(n_array = f_array; n_array < l_array; n_array++)
    {
        *n_array = (rand() % 201) - 100;
    }

    // Вивід елементів масиву
    for(n_array = f_array; n_array < l_array; n_array++)
    {
        printf("%4d", *n_array);
    }
    printf("\n");

    // Зміна розміру масиву
    int new_size;
    printf("Enter the new array size: ");
    scanf("%d", &new_size);
    Array = (int*)realloc(Array, new_size * sizeof(int));
    if(Array == NULL){
        printf("Memory not reallocated");
        return 1;
    }

    f_array = &Array[0];
    l_array = Array + new_size;

    // Заповнення нового масиву
    if (new_size > N) {
        for(n_array = Array + N; n_array < l_array; n_array++)
        {
            *n_array = (rand() % 201) - 100;
        }
    }

    // Вивід елемент
    for(n_array = f_array; n_array < l_array; n_array++)
    {
        printf("%4d", *n_array);
    }
    printf("\n");

    free(Array);
    return 0;
}
