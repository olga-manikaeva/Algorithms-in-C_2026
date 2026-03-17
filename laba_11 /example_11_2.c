#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N;
    printf("Enter the initial array size: ");
    scanf("%d", &N);
    
    float *Array = (float*)calloc(N, sizeof(float));
    if(Array == NULL){
        printf("Memory not allocated");
        return 1;
    }
    float *n_array; // поточний елемент
    float *f_array; // перший елемент
    float *l_array; // останній елемент

    f_array = &Array[0];
    l_array = Array + N;

    // Заповнення масиву випадковими числами
    srand(time(NULL));
    n_array = f_array;
    do {
        *n_array = (float)rand() / (float)(RAND_MAX / 100);
        n_array++;
    } while(n_array < l_array);

    // Вивід елементів масиву
    n_array = f_array;
    do {
        printf("%4.2f ", *n_array);
        n_array++;
    } while(n_array < l_array);
    printf("\n");

    free(Array);
    return 0;
}
