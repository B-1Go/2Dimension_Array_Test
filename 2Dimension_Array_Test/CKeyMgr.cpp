#include "CKeyMgr.h"

CKeyMgr::CKeyMgr()
{
}

CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::update()
{
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
					break;
				case (int)Diraction::LEFT:
					cout << "왼쪽" << endl;
					break;
				case (int)Diraction::RIGHT:
					cout << "오른쪽" << endl;
					break;
				case (int)Diraction::DOWN:
					cout << "아래" << endl;
					break;
				}
			}
		}
	}
}
