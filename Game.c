#include "HeaderGameFunc.h"
#include <stdio.h>

extern int** open;
extern int** matrix;
extern int Level;
extern level list[3];

void levels() {
    list[0].N_M = list[0].N_X = list[0].N_Y = 10;

    list[1].N_M = 40;
    list[1].N_X = 16;
    list[1].N_Y = 16;

    list[2].N_M = 99;
    list[2].N_X = 30;
    list[2].N_Y = 16;
}

void InitializeGameFields() //ініціалізація полів 
{
    levels();
    matrix = (int**)malloc(list[2].N_Y * sizeof(int*) + list[2].N_X * list[2].N_Y * sizeof(int));
    int* m_start = (int*)((char*)matrix + list[2].N_Y * sizeof(int*));
    for (int i = 0; i < list[2].N_Y; i++)
        matrix[i] = m_start + i * list[2].N_X;

    open = (int**)malloc(list[2].N_Y * sizeof(int*) + list[2].N_X * list[2].N_Y * sizeof(int));
    int* start = (int*)((char*)open + list[2].N_Y * sizeof(int*));
    for (int i = 0; i < list[2].N_Y; i++)
        open[i] = start + i * list[2].N_X;
}

void Cleaner() { //очищення динамічної памяті
    free(matrix);
    free(open);
}

// створення ігрового поля, заповнення масивів нулями
void CreatField() {
    int x, y;
    for (y = 0; y < list[Level].N_Y; y++) {
        for (x = 0; x < list[Level].N_X; x++) {
            matrix[y][x] = 0;
            open[y][x] = 0;
        }
    }
    // заповнюємо масив поля мінами
    for (int i = 0; i < list[Level].N_M; i++) {
        do {
            y = rand() % list[Level].N_Y; x = rand() % list[Level].N_X;
        } while (matrix[y][x] != 0);
        matrix[y][x] = -1;
    }
    // заповнюємо масив поля цифрами
    for (y = 0; y < list[Level].N_Y; y++) {
        for (x = 0; x < list[Level].N_X; x++) {
            int n = 0;
            if (matrix[y][x] != -1) {
                if (mine(y - 1, x - 1)) n++;
                if (mine(y - 1, x)) n++;
                if (mine(y - 1, x + 1)) n++;
                if (mine(y, x - 1)) n++;
                if (mine(y, x + 1)) n++;
                if (mine(y + 1, x - 1)) n++;
                if (mine(y + 1, x)) n++;
                if (mine(y + 1, x + 1)) n++;
                matrix[y][x] = n;
            }
        }
    }
}

int GameControl(int* x, int* y) { // управління курсором
    char c;
    do {
        c = _getch();
        switch (c) {
        case LEFT: if (control(*x - 1, *y))--* x; break;
        case RIGHT: if (control(*x + 1, *y))++* x; break;
        case UP: if (control(*x, *y - 1))--* y; break;
        case DOWN: if (control(*x, *y + 1))++* y; break;
        case SPACES: // встановлення прапорця на обрану позицію
            if (open[*y][*x] != 1) {
                if (open[*y][*x] != -1) open[*y][*x] = -1;
                else open[*y][*x] = 0;
            }
            break;
        case ESCAPE:
            printf(" \n\tВи завершили гру");
            Cleaner();
            getchar();
            return ESCAPE; // завершення гри
        }
        system("cls");
        DrawMatrix(*y, *x);
    } while (c != ENTER); // відкриття комірки при натискані клавіші ENTER 
    return ENTER;
}

// рекурсивна функція, яка відкриває поля в точці попадання
void OpenСell(int y, int x) {
    if ((y >= 0) && (y < list[Level].N_Y)) {
        if ((x >= 0) && (x < list[Level].N_X)) {
            // перевірка, чи не було відкрито поле раніше
            if (!open[y][x]) {
                open[y][x] = 1; // відкриємо
                // якщо поле пусте,  відкриваємо всіх його сусідів
                if (matrix[y][x] == 0) {
                    OpenСell(y - 1, x - 1);
                    OpenСell(y - 1, x);
                    OpenСell(y - 1, x + 1);
                    OpenСell(y, x - 1);
                    OpenСell(y, x + 1);
                    OpenСell(y + 1, x - 1);
                    OpenСell(y + 1, x);
                    OpenСell(y + 1, x + 1);
                }
            }
        }
    }
}

int control(int x, int y)
{ //перевірка координат, щоб курсор не вийшов за межі поля
    if ((x >= 0) && (x < list[Level].N_X))
        if ((y >= 0) && (y < list[Level].N_Y))
            return 1;
    return 0;
}

// перевіряє комірку на міну
int mine(int y, int x) {
    if ((y >= 0) && (y < list[Level].N_Y)) {
        if ((x >= 0) && (x < list[Level].N_X)) {
            if (matrix[y][x] == -1) return 1;
        }
    }
    return 0;
}

// в разі програшу ця функція відкриє всі міни
void OpenMines() {
    for (int y = 0; y < list[Level].N_Y; y++) {
        for (int x = 0; x < list[Level].N_X; x++) {
            if (matrix[y][x] == -1) open[y][x] = 1;
        }
    }
}

// перевірка поля після розкриття всіх нерозмінованих комірок
int CheckVictory() {
    for (int y = 0; y < list[Level].N_Y; y++) {
        for (int x = 0; x < list[Level].N_X; x++) {
            if ((matrix[y][x] != -1) && (!open[y][x])) return 0;
        }
    }
    return 1;
}