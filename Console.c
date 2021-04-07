#include "HeaderGameFunc.h"
#include <stdio.h>
#include <stdlib.h>

extern int** open;
extern int** matrix;
extern int Level;
extern level list[3];


void Representation() {//передмова
    InitializeGameFields();
    printf("\n\t\tMinesweeper \n\n Правила гри:\n"
        "\n\tОбережно відкривайте комірки поля.\n"
        "\tВідкрита комірка вказує на кількість мін,\n\tякі знаходяться навколо неї.\n"
        "\tЩоб пройти рівень, розкрийте всі комірки, не влучивши в міну.\n"
        "\n Управління:\n\n\tENTER - відкрити комірку\n\tSPACE - розмістити прапорець"
        "\n\tLEFT, RIGHT, UP, DOWN - керування курсором\n\tESC - вийти з гри"
        "\n\n\tГра має три рівні (Новачок-Любитель-Професіонал)"
        "\n\tЩоб виграти, пройдіть усі рівні поспіль без поразки. Успіхів :)\n"
        "\n Натисніть будь-яку клавішу, щоб продовжити...");
    getchar();
}

// вивід поля з урахуванням відкритих і закритих комірок
void DrawMatrix(int i, int j) {
    printf(" Рівень № %d\n", Level + 1);
    frame();
    for (int y = 0; y < list[Level].N_Y; y++) {
        putchar('|');
        for (int x = 0; x < list[Level].N_X; x++) {
            if (open[y][x] != 0 && open[y][x] != -1) {
                if (matrix[y][x] == -1) {
                    // Escape-послідовності задають забарвлення фону та шрифту
                    printf("\033[41m*\033[0m");
                }
                else if (matrix[y][x] == 0) {
                    if (y == i && x == j)  printf("\033[107m \033[0m");
                    else printf("\033[47m \033[0m");
                }
                else if (matrix[y][x] == 1) {
                    if (y == i && x == j) printf("\033[107m\033[94m%d\033[0m", matrix[y][x]);
                    else  printf("\033[47m\033[94m%d\033[0m", matrix[y][x]);
                }
                else if (matrix[y][x] == 2) {
                    if (y == i && x == j) printf("\033[107m\033[92m%d\033[0m", matrix[y][x]);
                    else printf("\033[47m\033[92m%d\033[0m", matrix[y][x]);
                }
                else if (matrix[y][x] == 3) {
                    if (y == i && x == j) printf("\033[107m\033[91m%d\033[0m", matrix[y][x]);
                    else printf("\033[47m\033[91m%d\033[0m", matrix[y][x]);
                }
                else if (matrix[y][x] == 4) {
                    if (y == i && x == j) printf("\033[107m\033[34m%d\033[0m", matrix[y][x]);
                    else printf("\033[47m\033[34m%d\033[0m", matrix[y][x]);
                }
                else if (matrix[y][x] == 5) {
                    if (y == i && x == j) printf("\033[107m\033[31m%d\033[0m", matrix[y][x]);
                    else printf("\033[47m\033[31m%d\033[0m", matrix[y][x]);
                }
                else if (matrix[y][x] == 6) {
                    if (y == i && x == j) printf("\033[107m\033[36m%d\033[0m", matrix[y][x]);
                    else printf("\033[47m\033[36m%d\033[0m", matrix[y][x]);
                }
                else if (matrix[y][x] == 7) {
                    if (y == i && x == j) printf("\033[107m\033[30m%d\033[0m", matrix[y][x]);
                    else printf("\033[47m\033[30m%d\033[0m", matrix[y][x]);
                }
                else if (matrix[y][x] == 8) {
                    if (y == i && x == j) printf("\033[107m\033[90m%d\033[0m", matrix[y][x]);
                    else printf("\033[47m\033[90m%d\033[0m", matrix[y][x]);
                }
            }
            else if (open[y][x] == -1) {
                if (y == i && x == j) printf("\033[107m\033[31mP\033[0m");
                else printf("\033[100m\033[31mP\033[0m");
            }
            else if (y == i && x == j) printf("\033[107m \033[0m");
            else printf("\033[40m \033[0m");
        }
        putchar('|');
        putchar('\n');
    }
    frame();
}

void frame() { //Вивід рамки
    int i;
    putchar('+');
    for (i = 0; i < list[Level].N_X; i++) {
        putchar('—');
    }
    putchar('+');
    putchar('\n');
}