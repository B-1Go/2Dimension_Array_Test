#include <iostream>
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::wcout;
using std::endl;
using std::string;

// let's make inventory! yeah~!!

class s_node
{
private:
	int x;
	int y;
	s_node* s_node_next;
};

class snake
{
private:
	int snake_length;
	s_node* snake_head;

public:
	void push_back();
	void erase();
};

enum class Diraction
{
	ESC = 27,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

// 깜빡이 차단용 입력 전용
bool isinput, gamestop;
// 포지션 저장 및 방향
int x, y, dir;
int inven_size = 10;
// 2차원 문자열 배열 동적 할당
string** s_matrix = new string * [inven_size];
void setup()
{
	for (int i = 0; i < inven_size; ++i)
	{
		s_matrix[i] = new string[inven_size];
	}

	x = 0; y = 0;
	gamestop = true;
}

void setup_clear()
{
	// 2차원 배열 동적 할당 해제
	for (int i = 0; i < inven_size; ++i)
	{
		delete[] s_matrix[i];
	}
	delete[] s_matrix;
}

void draw()
{
	system("cls");
	// inventory 창
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			cout << s_matrix[i][j];
		}
		cout << endl;
	}
	isinput = true;
}

void input()
{
	if (_kbhit())
	{
		char c = _getch();
		if (c == -32)
		{
			c = _getch();

			switch (c)
			{
			case (int)Diraction::UP:
				dir = (int)Diraction::UP;
				break;
			case (int)Diraction::LEFT:
				dir = (int)Diraction::LEFT;
				break;
			case (int)Diraction::RIGHT:
				dir = (int)Diraction::RIGHT;
				break;
			case (int)Diraction::DOWN:
				dir = (int)Diraction::DOWN;
				break;
			default:
				dir = 0;
				break;
			}
		}
		else if (c == (int)Diraction::ESC)
		{
			dir = (int)Diraction::ESC;
		}
		isinput = false;
	}
}

void update()
{
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			s_matrix[i][j] = "□";
		}
	}

	s_matrix[x][y] = "■";
}

void logic()
{
	switch (dir)
	{
	case (int)Diraction::UP:
		if (x <= 0) {}
		else { x--; }
		dir = 0;
		break;
	case (int)Diraction::LEFT:
		if (y <= 0) {}
		else { y--; }
		dir = 0;
		break;
	case (int)Diraction::RIGHT:
		if (y >= inven_size - 1) {}
		else { y++; }
		dir = 0;
		break;
	case (int)Diraction::DOWN:
		if (x >= inven_size - 1) {}
		else { x++; }
		dir = 0;
		break;
	case (int)Diraction::ESC:
		gamestop = false;
		break;
	default:
		dir = 0;
		break;
	}
}

int main()
{
	setup();

	while (gamestop)
	{
		update();
		draw();
		while (isinput)
		{
			input();
		}
		logic();
	}

	setup_clear();
	return 0;
}