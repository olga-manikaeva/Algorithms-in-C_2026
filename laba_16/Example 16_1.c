#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>   // <ncurses.h>, для Windows: <curses.h>
#include <unistd.h>    // Для usleep()

int main() {
    int N;
    WINDOW *windowInput, *windowOutput;

    initscr();           // Ініціалізація curses
    start_color();       // Запуск кольорового режиму

    if (!has_colors()) {
        endwin();
        fprintf(stderr, "Colors are not supported!\n");
        return 1;
    }

    curs_set(0);         // Приховати курсор
    cbreak();            // Ввід символів без Enter
    noecho();            // Не відображати введені символи

    // Ініціалізація пар кольорів
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(3, COLOR_BLUE, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(14, COLOR_WHITE, COLOR_BLACK);

    // Вивід тексту
    move(2, 27);
    attron(COLOR_PAIR(1));
    printw("Good ");
    attron(COLOR_PAIR(2));
    printw("Morning! ");
    attron(COLOR_PAIR(3));
    printw("Have a nice day!");
    refresh();

    // Анімація лінії
    int x, y = 3;
    for (x = 20; x < 60; x++) {
        mvaddch(y, x, '-');
        refresh();
        usleep(10000); // 10 мс
    }

    // Вікно вводу
    windowInput = newwin(15, 70, 6, 5);
    wbkgd(windowInput, COLOR_PAIR(5));
    box(windowInput, 0, 0);
    mvwprintw(windowInput, 0, 2, "First window");
    wrefresh(windowInput);

    // Вікно виводу
    windowOutput = newwin(10, 16, 8, 8);
    box(windowOutput, 0, 0);
    mvwprintw(windowOutput, 0, 2, "window");
    wrefresh(windowOutput);

    // Введення числа
    move(10, 9);
    attron(COLOR_PAIR(4));
    printw("Input N: ");
    refresh();
    echo(); // Показати введення
    scanw("%d", &N);
    noecho(); // Знову приховати

    // Оновлення вікон
    box(windowInput, 0, 0);
    mvwprintw(windowInput, 0, 2, "First window");
    wrefresh(windowInput);

    box(windowOutput, 0, 0);
    mvwprintw(windowOutput, 0, 2, "window");
    wrefresh(windowOutput);

    move(10, 9);
    attron(COLOR_PAIR(14));
    printw("Input N: %d", N);

    move(12, 9);
    printw("N = %d", N);

    getch();
    endwin(); // Завершення curses

    return 0;
}
