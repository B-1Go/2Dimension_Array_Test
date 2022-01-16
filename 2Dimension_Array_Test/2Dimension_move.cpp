#include <iostream>
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::wcout;
using std::endl;
using std::string;

// let's catch keyboard input!!
enum class Diraction
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

int main()
{
	// 2���� ���ڿ� �迭 ���� �Ҵ�
	string** s_matrix = new string * [5];
	for (int i = 0; i < 5; ++i)
	{
		s_matrix[i] = new string[5];
	}

	// ��ĭ���� ä���
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			s_matrix[i][j] = "��";
		}
	}

	// ������ ����
	int x = 2;
	int y = 2;
	s_matrix[x][y] = "��";

	// ����ϱ�
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << s_matrix[i][j];
		}
		cout << endl;
	}

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
					cout << "��" << endl;
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
					cout << "����" << endl;
					system("cls");
					if (0 >= y)
					{}
					else
					{
						s_matrix[x][y] = "��";
						y = y - 1;
						s_matrix[x][y] = "��";
					}
					break;
				case (int)Diraction::RIGHT:
					cout << "������" << endl;
					system("cls");
					if (4 <= y)
					{}
					else
					{
						s_matrix[x][y] = "��";
						y = y + 1;
						s_matrix[x][y] = "��";
					}
					break;
				case (int)Diraction::DOWN:
					cout << "�Ʒ�" << endl;
					system("cls");
					if (4 <= x)
					{}
					else
					{
						s_matrix[x][y] = "��";
						x = x + 1;
						s_matrix[x][y] = "��";
					}
					break;
				}

				// ����ϱ�
				for (int i = 0; i < 5; ++i)
				{
					for (int j = 0; j < 5; ++j)
					{
						cout << s_matrix[i][j];
					}
					cout << endl;
				}
			}
		}
	}

	// 2���� �迭 ���� �Ҵ� ����
	for (int i = 0; i < 5; ++i)
	{
		delete[] s_matrix[i];
	}
	delete[] s_matrix;
	return 0;
}