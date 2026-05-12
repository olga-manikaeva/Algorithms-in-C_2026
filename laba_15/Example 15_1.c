#include <stdio.h>
#include <stdlib.h>

char* print_2system(int numeric);

int main() {
    
    int A, B, C, D, E;
    
    printf("Приклад 1_1\n");
    //Побітовий зсув вліво (<<) і побітовий зсув вправо (>>)
    A = 19; // A = 00010011
    printf("A = %d = %s\n", A, print_2system(A));
    //Зсув вліво на 2 біти
    B = A << 2;
    printf("B = A << 2 = %d = %s\n", B, print_2system(B));
    //Зсув вправо на 2 біти
    C = B >> 2; // C = 00000101
    printf("C = B >> 2 = %d = %s\n", C, print_2system(C));
    
    printf("Приклад 1_2\n");
    //Побітовий оператор НЕ
    A = 17; // A = 00010001
    printf("A = %d = %s\n", A, print_2system(A));
    //Використання побітового оператора НЕ
    B = ~ A; // B = 11101100
    printf("B = ~ A = %d = %s\n", B, print_2system(B));

    // Побітові оператори І(&), АБО(I) та виключне АБО (XOR)
    printf("Приклад 1_3\n");
    A = 15; // A = 00001111
    printf("A = %d = %s\n", A, print_2system(A));
    B = 21; // B = 00010101
    printf("B = %d = %s\n", B, print_2system(B));
    C = A & B; // C = 00000101
    printf("C = A & B = %d = %s\n", C, print_2system(C));
    D = A | B; // D = 00011111
    printf("D = A | B = %d = %s\n", D, print_2system(D));
    E = A ^ B;  // E = 00011010
    printf("E = A ^ B = %d = %s\n", E, print_2system(E));
    
    return 0;
}

char* print_2system(int numeric) {
    static char BinaryNumber[9]; // Розмір типу даних: 8 біт + '\0'
    
    for (int i = 7; i >= 0; i--) {
        if (numeric & (1 << i)) {
            BinaryNumber[7 - i] = '1';
        } else {
            BinaryNumber[7 - i] = '0';
        }
    }
    
    BinaryNumber[8] = '\0'; // Завершення рядка
    return BinaryNumber;
}
