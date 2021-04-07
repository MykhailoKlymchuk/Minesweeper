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

void Representation(); // ��������� ���

void levels(); // ��� ���

void Game(); // ������� ������� ���

void InitializeGameFields(); //����������� ���� 

int GameControl(int*, int*); // ��������� ��������

void Cleaner(); //�������� �������� �����

void CreatField(); // ��������� �������� ����, ���������� ������ ������

// ���� ���� � ����������� �������� � �������� ������
void DrawMatrix(int, int);

void frame(); // ���� �����

//�������� ���������, ��� ������ �� ������ �� ��� ����
int control(int, int);

int mine(int, int); // �������� ������ �� ���

// ���������� �������, ��� ������� ���� � ����� ���������
void Open�ell(int, int);

void OpenMines(); // � ��� ��������, ������� ����� �� ���

// �������� ���� ���� ��������� ��� ������������� ������
int CheckVictory();

#endif
