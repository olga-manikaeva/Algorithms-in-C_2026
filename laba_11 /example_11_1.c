#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N;
    printf("Enter the array size: ");
    scanf("%d", &N);
    
    int *Array = (int*)malloc(N * sizeof(int));
    if(Array==NULL){
        printf("Memory not allocated");
        return 1;
    }
    int *n_array;//вказівник на поточний елемент
    int *f_array;//перший елемент масиву
    int *l_array;//останній елемент масиву

    f_array = &Array[0];
    l_array = Array + N;
    // Заповнення масиву
    srand(time(NULL));
    for(n_array=f_array;n_array<l_array;n_array++)
    {
        *n_array = rand()%101;
    }
    // Вивід елементів масиву
    f_array = &Array[0];
    for(n_array=f_array;n_array<l_array;n_array++)
    {
        printf("%4d",*n_array);
    }
    printf("\n");
    
    // Вивід елементів масиву в зворотньому порядку
    l_array = Array + N - 1;
    for(n_array=l_array;n_array>=f_array;n_array--)
    {
        printf("%4d",*n_array);
    }
    printf("\n");
    
    free(Array);
    return 0;
}
