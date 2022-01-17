#include <iostream>
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::wcout;
using std::endl;
using std::string;

// let's make inventory! yeah~!!

class item
{
private:
	string name;
	int at;
	int price;

public:
	void set(string _name, int _at, int _price);
	string get_name();
	int get_at();
	int get_price();

public:
	item()
		: name("없음")
		, at(0)
		, price(0)
	{}
	item(string _name, int _at, int _price)
		: name(_name)
		, at(_at)
		, price(_price)
	{}
	~item()
	{}
};

void item::set(string _name, int _at, int _price)
{
	name = _name;
	at = _at;
	price = _price;
}

string item::get_name()
{
	return string(name);
}

int item::get_at()
{
	return at;
}

int item::get_price()
{
	return price;
}

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
// 인벤과 같은 크기로 아이템 자료형 동적 할당함
int inven_size = 10;
item** inventory = new item * [inven_size];
// 2차원 문자열 배열 동적 할당
string** s_matrix = new string * [inven_size];
void setup()
{
	for (int i = 0; i < inven_size; ++i)
	{
		inventory[i] = new item[inven_size];
	}

	for (int i = 0; i < inven_size; ++i)
	{
		s_matrix[i] = new string[inven_size];
	}

	x = 0; y = 0;
	gamestop = true;
}

void setup_clear()
{
	// 인벤 item 동적 할당 해제
	for (int i = 0; i < inven_size; ++i)
	{
		delete[] inventory[i];
	}
	delete[] inventory;

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

	// 인벤 안에 아이템 출력하기
	cout << "-------------------------------------" << endl;
	cout << "이  름 : " << inventory[x][y].get_name() << endl;
	cout << "공격력 : " << inventory[x][y].get_at() << endl;
	cout << "가  격 : " << inventory[x][y].get_price() << endl;

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
			if (i == x && j == y)
			{
				s_matrix[i][j] = "■";
			}
			else
			{
				s_matrix[i][j] = "□";
			}
		}
	}
}

void logic()
{
	switch (dir)
	{
	case (int)Diraction::UP:
		if (x <= 0){}
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