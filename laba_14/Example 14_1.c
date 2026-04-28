#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char Name[30];
    float price;
    int number;
} P;

void createFile(FILE *); // створення нового файлу
void print(FILE *);      // перегляд файлу
void app(FILE *);        // додавання в файл
void find(FILE *);       // пошук і зміна

int main() {
    char c;
    FILE * ptr = NULL;
    while (1) {
        puts("\nMenu:");
        puts("1 - New file");
        puts("2 - View file");
        puts("3 - Add to file");
        puts("4 - Search and Change");
        puts("0 - Exit");
        printf("Choose: ");
        
        char inputBuf[10];
        fgets(inputBuf, sizeof(inputBuf), stdin);
        c = inputBuf[0];
        
        switch (c) {
            case '1': createFile(ptr); break;
            case '2': print(ptr); break;
            case '3': app(ptr); break;
            case '4': find(ptr); break;
            case '0': return 0;
            default: puts("Wrong input. Try again.");
        }
    }
}

void createFile(FILE * ptr) {
    ptr = fopen("/Users/olga/Documents/xcode/laba_14_1/laba_14_1/file.dat", "wb");
    if (!ptr) {
        perror("Cannot open file");
        return;
    }
    
    struct Product P;
    char ch;
    
    printf("\nNew product:\n");
    do {
        printf("Name: ");
        scanf("%s", P.Name);
        printf("Price: ");
        scanf("%f", &P.price);
        printf("Number: ");
        scanf("%d", &P.number);
        fwrite(&P, sizeof(P), 1, ptr);
        printf("Add another? y/n: ");
        while ((ch = getchar()) != '\n' && ch != EOF); // flush
        ch = getchar();
    } while (ch != 'n');
    
    fclose(ptr);
}

void print(FILE * ptr) {
    ptr = fopen("/Users/olga/Documents/xcode/laba_14_1/laba_14_1/file.dat", "rb");
    if (!ptr) {
        perror("Cannot open file");
        return;
    }
    
    struct Product P;
    int i = 1;
    
    printf("+-----+------------------------------+----------+----------+\n");
    printf("| No. | Name                         |  Price   | Quantity |\n");
    printf("+-----+------------------------------+----------+----------+\n");
    
    while (fread(&P, sizeof(P), 1, ptr)) {
        printf("| %3d | %-28s | %8.2f | %8d |\n", i, P.Name, P.price, P.number);
        i++;
    }
    
    printf("+-----+------------------------------+----------+----------+\n");
    
    fclose(ptr);
}

void app(FILE * ptr) {
    ptr = fopen("/Users/olga/Documents/xcode/laba_14_1/laba_14_1/file.dat", "ab");
    if (!ptr) {
        perror("Cannot open file");
        return;
    }
    
    struct Product P;
    char ch;
    
    printf("\nAdd product:\n");
    do {
        printf("Name: ");
        scanf("%s", P.Name);
        printf("Price: ");
        scanf("%f", &P.price);
        printf("Number: ");
        scanf("%d", &P.number);
        fwrite(&P, sizeof(P), 1, ptr);
        printf("Add another? y/n: ");
        while ((ch = getchar()) != '\n' && ch != EOF); // flush
        ch = getchar();
    } while (ch != 'n');
    
    fclose(ptr);
}

void find(FILE * ptr) {
    ptr = fopen("/Users/olga/Documents/xcode/laba_14_1/laba_14_1/file.dat", "rb+");
    if (!ptr) {
        perror("Cannot open file");
        return;
    }
    
    struct Product P;
    char name[30];
    int found = 0;
    
    printf("Enter product name to search: ");
    scanf("%s", name);
    
    while (fread(&P, sizeof(P), 1, ptr)) {
        if (strcmp(P.Name, name) == 0) {
            printf("Found: %10s | Price: %.2f | Quantity: %d\n", P.Name, P.price, P.number);
            printf("Change this product? y/n: ");
            while (getchar() != '\n'); // flush buffer
            char ch = getchar();
            if (ch == 'y') {
                printf("New quantity: ");
                scanf("%d", &P.number);
                printf("New price: ");
                scanf("%f", &P.price);
                fseek(ptr, -sizeof(P), SEEK_CUR);
                fwrite(&P, sizeof(P), 1, ptr);
                puts("Updated successfully.");
            }
            found = 1;
            break;
        }
    }
    
    if (!found) {
        puts("Product not found.");
    }
    
    fclose(ptr);
}
