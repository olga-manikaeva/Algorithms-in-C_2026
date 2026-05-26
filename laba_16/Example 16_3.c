#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h> // для usleep()
#include <stdlib.h> // для rand() і srand()

int main() {
    int a[10];     // Масив із 10 елементів
    int i;         // Лічильник

    // --- Генерація випадкових чисел ---
    srand(time(NULL)); // Ініціалізація генератора

    for (i = 0; i < 10; i++) {
        a[i] = rand() % 10; // Випадкові числа від 0 до 9
    }

    // --- Ініціалізація ncurses ---
    initscr();             // Запуск ncurses
    start_color();         // Увімкнення кольору
    cbreak();
    noecho();

    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support colors.\n");
        return 1;
    }

    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Зелений текст

    attron(COLOR_PAIR(1)); // Застосувати зелений стиль

    // --- Вивід масиву у терміналі ncurses ---
    mvprintw(2, 4, "Generated array:");

    for (i = 0; i < 10; i++) {
        mvprintw(4, 4 + i * 4, "%d", a[i]); // Виводимо числа з відступом
        refresh();
        usleep(100000); // Затримка 100 мс для ефекту
    }

    attroff(COLOR_PAIR(1)); // Вимкнути колір

    mvprintw(6, 4, "Press any key to exit...");
    getch();
    endwin();

    return 0;
}
