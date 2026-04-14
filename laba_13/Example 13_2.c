#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

const int M = 2;

int main() {
    {
        
        //SetConsoleCP(1251);
        //SetConsoleOutputCP(1251);
        
        int j,i;
        FILE *fp; // вказівник на файл
        char Address [] = "/Users/olga/Documents/laba_13/laba_13/input_13_2.txt";
        fp = fopen(Address,"r"); // Абсолютний шлях до файлу XCode
        if (fp == NULL) {
                perror("Не вдалося відкрити файл для читання");
                return 1;
        }
        
        int N = 0;
        
        while(fscanf(fp,"%*[^\n]%*c")!=EOF)
        {
            N++;
        }
        printf("N = %d \n",N);
        
        int *A = (int*)malloc(N*M*sizeof(int));
        int *B = (int*)malloc(N*sizeof(int));
        
        if (A == NULL || B == NULL) {
                printf("Помилка виділення пам'яті.\n");
                fclose(fp);
                return 1;
        }
        rewind(fp);
        
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                fscanf(fp,"%d",(A+i*M+j));
                printf("A[%1d][%1d] = %2d  ",i+1,j+1,*(A+i*M+j));
                B[i] = *(A+i*M)+*(A+i*M+j);
                
            }
            printf(" | B[%d] = %d",i+1,B[i]);
            printf("\n");
            
        }
        
        fp=fopen("/Users/olga/Documents/laba_13/laba_13/output_13_2.txt","w");
        for(i=0; i<N; i++)
        {
            fprintf(fp,"%d\n",B[i]);
            
        }
        
        fclose(fp);
        free(A);
        free(B);
        
    }
}
