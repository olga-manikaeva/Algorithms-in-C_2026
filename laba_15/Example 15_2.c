#include <stdio.h>

char* print_2system(int numeric);
int encode(int x);  // функція кодування
int decode(int y);  // функція декодування

int main() {
    int original, encoded, decoded;

    // Початкове число
    printf("Введіть число для кодування: ");
    scanf("%d", &original);
    
    printf("Початкове число:\n");
    printf("original = %d = %s\n", original, print_2system(original));

    // Кодування
    encoded = encode(original);
    printf("\nПісля кодування:\n");
    printf("encoded  = %d = %s\n", encoded, print_2system(encoded));

    // Декодування
    decoded = decode(encoded);
    printf("\nПісля декодування:\n");
    printf("decoded  = %d = %s\n", decoded, print_2system(decoded));

    return 0;
}

// Кодування: XOR з маскою, потім зсув вліво
int encode(int x) {
    return ((x ^ 0b01010101) << 1) & 0xFF;
}

// Декодування: зсув вправо, потім XOR з тією ж маскою
int decode(int y) {
    return (y >> 1) ^ 0b01010101;
}

// Друк у двійковому форматі
char* print_2system(int numeric) {
    static char BinaryNumber[9];
    for (int i = 7; i >= 0; i--) {
        BinaryNumber[7 - i] = (numeric & (1 << i)) ? '1' : '0';
    }
    BinaryNumber[8] = '\0';
    return BinaryNumber;
}
