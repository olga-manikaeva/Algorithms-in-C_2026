#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_N 100

struct Student {
    char Name[NAME_N];
    int Rating;
};

int main() {
    int count;
    printf("Скільки студентів? ");
    scanf("%d", &count);
    getchar();

    struct Student *students = malloc(count * sizeof(struct Student));
    if (students == NULL) {
        perror("Помилка виділення пам'яті");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Введіть ПІБ студента %d: ", i + 1);
        fgets(students[i].Name, NAME_N, stdin);
        students[i].Name[strcspn(students[i].Name, "\n")] = '\0';

        printf("Оцінка: ");
        scanf("%d", &students[i].Rating);
        getchar();
    }

    FILE *fp = fopen("/Users/olga/Documents/laba_13/laba_13/rating_13_4.txt", "w");
    if (fp == NULL) {
        perror("Не вдалося відкрити файл");
        free(students);
        return 1;
    }

    fprintf(fp, "+----------------------------+--------+\n");
    fprintf(fp, "|           ПІБ              | Рейтинг|\n");
    fprintf(fp, "+----------------------------+--------+\n");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "| %-26s | %6d |\n", students[i].Name, students[i].Rating);
    }
    fprintf(fp, "+----------------------------+--------+\n");

    fclose(fp);
    free(students);

    printf("Дані успішно записані в файл!\n");

    return 0;
}
