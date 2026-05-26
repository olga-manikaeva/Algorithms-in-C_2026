#include <ncurses.h>
#include <unistd.h> // для usleep()

int fact(int n);

int main() {
    int N;

    // --- Ініціалізація ncurses ---
    initscr();             // Запуск ncurses
    cbreak();              // Без Enter
    noecho();              // Приховати введення
    curs_set(1);           // Показати курсор
    keypad(stdscr, TRUE);  // Увімкнути клавіші
    start_color();         // Увімкнути кольори

    // --- Перевірка кольорів ---
    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support colors.\n");
        return 1;
    }

    // --- Ініціалізація кількох пар кольорів ---
    init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(2, COLOR_GREEN,   COLOR_BLACK);
    init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(4, COLOR_BLUE,    COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN,    COLOR_BLACK);
    init_pair(7, COLOR_WHITE,   COLOR_BLACK);

    // --- Ввід числа ---
    mvprintw(2, 4, "Enter a number: ");
    echo(); // Дозволити введення
    scanw("%d", &N);
    noecho();

    // --- Вивід факторіалів з кольорами ---
    int y = 4;
    for (int i = 1; i <= N; i++) {
        int result = fact(i);

        int color_pair = (i % 7) + 1; // Циклічно використовуємо 7 кольорів
        attron(COLOR_PAIR(color_pair));
        mvprintw(y++, 6, "%2d! = %d", i, result);
        attroff(COLOR_PAIR(color_pair));
        refresh();
        usleep(100000); // 100 мс затримка для ефекту
    }

    // --- Завершення ---
    mvprintw(y + 2, 4, "Press any key to exit...");
    refresh();
    getch();
    endwin();

    return 0;
}

// --- Обчислення факторіала рекурсивно ---
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}
