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
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

int main()
{
	int inven_size = 20;

	// 인벤과 같은 크기로 아이템 자료형 동적 할당함
	item** inventory = new item * [inven_size];
	for (int i = 0; i < inven_size; ++i)
	{
		inventory[i] = new item[inven_size];
	}

	// 2차원 문자열 배열 동적 할당
	string** s_matrix = new string * [inven_size];
	for (int i = 0; i < inven_size; ++i)
	{
		s_matrix[i] = new string[inven_size];
	}

	// 빈칸으로 채우기
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			s_matrix[i][j] = "□";
		}
	}

	// 포지션 저장
	int x = 0;
	int y = 0;
	s_matrix[x][y] = "■";

	// 출력하기
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			cout << s_matrix[i][j];
		}
		cout << endl;
	}

	// 인벤 안에 데이터 출력하기
	cout << "-------------------------------------" << endl;
	cout << "이  름 : " << inventory[x][y].get_name() << endl;
	cout << "공격력 : " << inventory[x][y].get_at() << endl;
	cout << "가  격 : " << inventory[x][y].get_price() << endl;

	// 키보드 입력감지 함수
	char c;
	while (true)
	{
		// 키보드가 감지되면 if문이 실행됨
		if (_kbhit())
		{
			c = _getch();
			if (c == -32) // char는 -127~128 만 표현이 가능해서 224 숫자가 들어오면 -32가 된다.
			{
				c = _getch();

				switch (c)
				{
				case (int)Diraction::UP:
					//cout << "위" << endl;
					system("cls");
					if (0 >= x)
					{
					}
					else
					{
						s_matrix[x][y] = "□";
						x = x - 1;
						s_matrix[x][y] = "■";
					}
					break;
				case (int)Diraction::LEFT:
					//cout << "왼쪽" << endl;
					system("cls");
					if (0 >= y)
					{
					}
					else
					{
						s_matrix[x][y] = "□";
						y = y - 1;
						s_matrix[x][y] = "■";
					}
					break;
				case (int)Diraction::RIGHT:
					//cout << "오른쪽" << endl;
					system("cls");
					if (inven_size - 1 <= y)
					{
					}
					else
					{
						s_matrix[x][y] = "□";
						y = y + 1;
						s_matrix[x][y] = "■";
					}
					break;
				case (int)Diraction::DOWN:
					//cout << "아래" << endl;
					system("cls");
					if (inven_size - 1 <= x)
					{
					}
					else
					{
						s_matrix[x][y] = "□";
						x = x + 1;
						s_matrix[x][y] = "■";
					}
					break;
				}

				// 인벤 위치 출력하기
				for (int i = 0; i < inven_size; ++i)
				{
					for (int j = 0; j < inven_size; ++j)
					{
						cout << s_matrix[i][j];
					}
					cout << endl;
				}

				// 인벤 안에 데이터 출력하기
				cout << "-------------------------------------" << endl;
				cout << "이  름 : " << inventory[x][y].get_name() << endl;
				cout << "공격력 : " << inventory[x][y].get_at() << endl;
				cout << "가  격 : " << inventory[x][y].get_price() << endl;
			}
		}
	}

	// 2차원 배열 동적 할당 해제
	for (int i = 0; i < inven_size; ++i)
	{
		delete[] s_matrix[i];
	}
	delete[] s_matrix;

	// 인벤 item 동적 할당 해제
	for (int i = 0; i < inven_size; ++i)
	{
		delete[] inventory[i];
	}
	delete[] inventory;

	return 0;
}