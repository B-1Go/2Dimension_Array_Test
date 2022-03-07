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
					break;
				case (int)Diraction::LEFT:
					cout << "����" << endl;
					break;
				case (int)Diraction::RIGHT:
					cout << "������" << endl;
					break;
				case (int)Diraction::DOWN:
					cout << "�Ʒ�" << endl;
					break;
				}
			}
		}
	}
}
