#include <stdio.h>

// Оголошення функцій
void add(int x, int y);
void subtract(int x, int y);
void multiply(int x, int y);
void divide(int x, int y);

int main(int argc, const char * argv[])
{
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("\n");

    // Масив вказівників на функції
    void (*operations[4])(int, int) = {add, subtract, multiply, divide};

    // Назви операцій (для виводу)
    const char *operation_names[4] = {"Додавання", "Віднімання", "Множення", "Ділення"};

    // Кількість операцій
    int length = sizeof(operations) / sizeof(operations[0]);

    for (int i = 0; i < length; i++)
    {
        printf("%s: ", operation_names[i]);
        operations[i](a, b);  // Виклик функції через вказівник
    }

    return 0;
}

// Реалізації функцій
void add(int x, int y) {
    printf("%d + %d = %d\n", x, y, x + y);
}

void subtract(int x, int y) {
    printf("%d - %d = %d\n", x, y, x - y);
}

void multiply(int x, int y) {
    printf("%d * %d = %d\n", x, y, x * y);
}

void divide(int x, int y) {
    if (y != 0)
        printf("%d / %d = %.2f\n", x, y, (float)x / y);
    else
        printf("Error: division on zero!\n");
}
