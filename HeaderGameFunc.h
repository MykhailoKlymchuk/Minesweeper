#ifndef HeaderGameFutc_H
#define HeaderGameFunc_H
#define LEFT 0x4b
#define RIGHT 0x4d
#define UP 0x48
#define DOWN 0x50
#define ENTER 0xd
#define SPACES 0x20
#define ESCAPE 0x1b

typedef struct Level {
	int N_X;
	int N_Y;
	int N_M;
}level;

void Representation(); // передмова гри

void levels(); // рівні гри

void Game(); // головна функція гри

void InitializeGameFields(); //ініціалізація полів 

int GameControl(int*, int*); // управління курсором

void Cleaner(); //очищення динамічної памяті

void CreatField(); // створення ігрового поля, заповнення масивів нулями

// вивід поля з урахуванням відкритих і закритих комірок
void DrawMatrix(int, int);

void frame(); // Вивід рамки

//перевірка координат, щоб курсор не вийшов за межі поля
int control(int, int);

int mine(int, int); // перевіряє комірку на міну

// рекурсивна функція, яка відкриває поля в точці попадання
void OpenСell(int, int);

void OpenMines(); // в разі програшу, функція відкриє всі міни

// перевірка поля після розкриття всіх нерозмінованих комірок
int CheckVictory();

#endif
