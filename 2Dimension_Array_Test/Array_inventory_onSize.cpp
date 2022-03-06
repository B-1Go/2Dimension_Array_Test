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
		: name("����")
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

	// �κ��� ���� ũ��� ������ �ڷ��� ���� �Ҵ���
	item** inventory = new item * [inven_size];
	for (int i = 0; i < inven_size; ++i)
	{
		inventory[i] = new item[inven_size];
	}

	// 2���� ���ڿ� �迭 ���� �Ҵ�
	string** s_matrix = new string * [inven_size];
	for (int i = 0; i < inven_size; ++i)
	{
		s_matrix[i] = new string[inven_size];
	}

	// ��ĭ���� ä���
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			s_matrix[i][j] = "��";
		}
	}

	// ������ ����
	int x = 0;
	int y = 0;
	s_matrix[x][y] = "��";

	// ����ϱ�
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			cout << s_matrix[i][j];
		}
		cout << endl;
	}

	// �κ� �ȿ� ������ ����ϱ�
	cout << "-------------------------------------" << endl;
	cout << "��  �� : " << inventory[x][y].get_name() << endl;
	cout << "���ݷ� : " << inventory[x][y].get_at() << endl;
	cout << "��  �� : " << inventory[x][y].get_price() << endl;

	// Ű���� �Է°��� �Լ�
	char c;
	while (true)
	{
		// Ű���尡 �����Ǹ� if���� �����
		if (_kbhit())
		{
			c = _getch();
			if (c == -32) // char�� -127~128 �� ǥ���� �����ؼ� 224 ���ڰ� ������ -32�� �ȴ�.
			{
				c = _getch();

				switch (c)
				{
				case (int)Diraction::UP:
					//cout << "��" << endl;
					system("cls");
					if (0 >= x)
					{
					}
					else
					{
						s_matrix[x][y] = "��";
						x = x - 1;
						s_matrix[x][y] = "��";
					}
					break;
				case (int)Diraction::LEFT:
					//cout << "����" << endl;
					system("cls");
					if (0 >= y)
					{
					}
					else
					{
						s_matrix[x][y] = "��";
						y = y - 1;
						s_matrix[x][y] = "��";
					}
					break;
				case (int)Diraction::RIGHT:
					//cout << "������" << endl;
					system("cls");
					if (inven_size - 1 <= y)
					{
					}
					else
					{
						s_matrix[x][y] = "��";
						y = y + 1;
						s_matrix[x][y] = "��";
					}
					break;
				case (int)Diraction::DOWN:
					//cout << "�Ʒ�" << endl;
					system("cls");
					if (inven_size - 1 <= x)
					{
					}
					else
					{
						s_matrix[x][y] = "��";
						x = x + 1;
						s_matrix[x][y] = "��";
					}
					break;
				}

				// �κ� ��ġ ����ϱ�
				for (int i = 0; i < inven_size; ++i)
				{
					for (int j = 0; j < inven_size; ++j)
					{
						cout << s_matrix[i][j];
					}
					cout << endl;
				}

				// �κ� �ȿ� ������ ����ϱ�
				cout << "-------------------------------------" << endl;
				cout << "��  �� : " << inventory[x][y].get_name() << endl;
				cout << "���ݷ� : " << inventory[x][y].get_at() << endl;
				cout << "��  �� : " << inventory[x][y].get_price() << endl;
			}
		}
	}

	// 2���� �迭 ���� �Ҵ� ����
	for (int i = 0; i < inven_size; ++i)
	{
		delete[] s_matrix[i];
	}
	delete[] s_matrix;

	// �κ� item ���� �Ҵ� ����
	for (int i = 0; i < inven_size; ++i)
	{
		delete[] inventory[i];
	}
	delete[] inventory;

	return 0;
}