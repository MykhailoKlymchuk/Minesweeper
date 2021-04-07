#include "HeaderGameFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// поле та допоміжний масив, що позначає відкриті поля
int** open;
int** matrix;
int Level = 1;
level list[3];

int main() {
    system("chcp 1251");
    system("cls");
    //srand(time(NULL));
    Representation();
    Game();
    return 0;
}

// головна функція гри ( рекурсивна у випадку виграшу )
void Game() {
    CreatField();
    int x = 0, y = 0;
    char c;
    // головний цикл
    while (1) {
        system("cls");
        DrawMatrix(y, x); //друк поля гри
        if (GameControl(&x, &y) == ESCAPE) return; //управління курсором
        OpenСell(y, x);
        system("cls");
        if (mine(y, x)) {  // перевірка на міну
            OpenMines();   // якщо міна знайденна, відкриваються усі міни
            DrawMatrix(y, x);
            printf("\n Нажаль Ви програли :(\n Спробуйте свої сили у новій грі\n");
            Cleaner();    // очищення памяті
            getchar();
            return;       //завершення гри
        }
        else if (CheckVictory()) { //повторна перевірка на виграш
            if (Level == 2) {
                printf("\n Не кожен зможе пройти усі рівні без поразки. \n Ви справжній Профі :)\n");
                getchar();
                return;
            }
            printf("\n Вітаю Ви виграли :)\n"
                "\n Бажаєте спробувати свої сили у складнішому рівні?\n\t 1 - ТАК \n\t 0 - НІ\n");
            c = _getch();
            switch (c) { //вибір продовження гри
            case '0':
                Cleaner();
                return;
            case '1':
                ++Level;
                Game();
                return;
            }
            break;
        }
    }
}