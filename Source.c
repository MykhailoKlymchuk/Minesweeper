#include "HeaderGameFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� �� ��������� �����, �� ������� ������ ����
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

// ������� ������� ��� ( ���������� � ������� ������� )
void Game() {
    CreatField();
    int x = 0, y = 0;
    char c;
    // �������� ����
    while (1) {
        system("cls");
        DrawMatrix(y, x); //���� ���� ���
        if (GameControl(&x, &y) == ESCAPE) return; //��������� ��������
        Open�ell(y, x);
        system("cls");
        if (mine(y, x)) {  // �������� �� ���
            OpenMines();   // ���� ��� ���������, ������������ �� ���
            DrawMatrix(y, x);
            printf("\n ������ �� �������� :(\n ��������� ��� ���� � ���� ��\n");
            Cleaner();    // �������� �����
            getchar();
            return;       //���������� ���
        }
        else if (CheckVictory()) { //�������� �������� �� ������
            if (Level == 2) {
                printf("\n �� ����� ����� ������ �� ��� ��� �������. \n �� �������� ����� :)\n");
                getchar();
                return;
            }
            printf("\n ³��� �� ������� :)\n"
                "\n ������ ���������� ��� ���� � ���������� ���?\n\t 1 - ��� \n\t 0 - Ͳ\n");
            c = _getch();
            switch (c) { //���� ����������� ���
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