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
	// 2차원 문자열 배열 동적 할당
	string** s_matrix = new string * [5];
	for (int i = 0; i < 5; ++i)
	{
		s_matrix[i] = new string[5];
	}

	// 빈칸으로 채우기
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			s_matrix[i][j] = "□";
		}
	}

	// 포지션 저장
	int x = 2;
	int y = 2;
	s_matrix[x][y] = "■";

	// 출력하기
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << s_matrix[i][j];
		}
		cout << endl;
	}

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
					cout << "위" << endl;
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
					cout << "왼쪽" << endl;
					system("cls");
					if (0 >= y)
					{}
					else
					{
						s_matrix[x][y] = "□";
						y = y - 1;
						s_matrix[x][y] = "■";
					}
					break;
				case (int)Diraction::RIGHT:
					cout << "오른쪽" << endl;
					system("cls");
					if (4 <= y)
					{}
					else
					{
						s_matrix[x][y] = "□";
						y = y + 1;
						s_matrix[x][y] = "■";
					}
					break;
				case (int)Diraction::DOWN:
					cout << "아래" << endl;
					system("cls");
					if (4 <= x)
					{}
					else
					{
						s_matrix[x][y] = "□";
						x = x + 1;
						s_matrix[x][y] = "■";
					}
					break;
				}

				// 출력하기
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

	// 2차원 배열 동적 할당 해제
	for (int i = 0; i < 5; ++i)
	{
		delete[] s_matrix[i];
	}
	delete[] s_matrix;
	return 0;
}