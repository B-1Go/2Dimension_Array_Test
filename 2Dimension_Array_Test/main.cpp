#include "global.h"
#include "CCore.h"



int main()
{
	bool system_msg = false; // Ŀ�� �� �ü���� �����ϴ� �κ��� ���������� ǥ��

	if (FAILED(CCore::GetInst()->init(POINT{10, 30})))
	{
		MessageBox(nullptr, L"Core ��ü �ʱ�ȭ ����", L"ERROR", MB_OK);

		return FALSE;
	}

	while (true)
	{
		if (system_msg)
		{
			cout << "OS�ܿ� �޼���ť�� �߻��߽��ϴ�." << endl;
			system_msg = false;
		}
		else
		{
			CCore::GetInst()->progress();
		}
	}
}