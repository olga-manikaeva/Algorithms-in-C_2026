#include <stdio.h>
#include <stdlib.h>

void print_2system(int numeric);

int main() {
    int a = 2;
    
    // Побітовий зсув:
    int r = (a << 4) - (a << 1) - (a << 0);
    printf("r = %d = ", r); print_2system(r);
    
    int A, B, C;
    
    // Виділити біти 1 та 2
    printf("\n\n**** Виділити біти 1 та 2 ****\n");
    A = 213; // 11010101
    B = 6;   // 00000110
    C = A & B;
    printf("A = "); print_2system(A);
    printf("\nB = "); print_2system(B);
    printf("\nC = "); print_2system(C);
    
    // Обнулити біти 1 та 2
    printf("\n\n**** Обнулити біти 1 та 2 ****\n");
    A = 213;
    B = 249; // 11111001
    C = A & B;
    printf("A = "); print_2system(A);
    printf("\nB = "); print_2system(B);
    printf("\nC = "); print_2system(C);
    
    // Установити біти 1 та 3
    printf("\n\n**** Установити біти 1 та 3 ****\n");
    A = 213;
    B = 10; // 00001010
    C = A | B;
    printf("A = "); print_2system(A);
    printf("\nB = "); print_2system(B);
    printf("\nC = "); print_2system(C);
    
    // Інверсія з обмеженням до 8 біт
    printf("\n\n**** Інверсія ****\n");
    A = 213;
    C = ~A & 0xFF;
    printf("A = "); print_2system(A);
    printf("\nC = "); print_2system(C);
    
    printf("\n");
    
    return 0;
}

void print_2system(int numeric) {
    for (int t = 128; t > 0; t /= 2) {
        if(numeric & t)
            printf("1");
        else
            printf("0");
    }
}
