#include "global.h"
#include "CCore.h"

HWND GetConsoleHwnd()
{
#define MY_BUFSIZE 1024
	WCHAR pszNewWindowTitle[MY_BUFSIZE]; 
	WCHAR pszOldWindowTitle[MY_BUFSIZE] = L"HelloConsole";
	HWND hwndFound;

	GetConsoleTitle(pszNewWindowTitle, MY_BUFSIZE);

	swprintf_s(pszNewWindowTitle, L"%d/%d", (int)GetTickCount64(), GetCurrentProcessId());

	SetConsoleTitle(pszNewWindowTitle);

	Sleep(40);

	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	SetConsoleTitle(pszOldWindowTitle);

	return(hwndFound);
}

int main()
{
	bool system_msg = false; // Ŀ�� �� �ü���� �����ϴ� �κ��� ���������� ǥ��

	if (FAILED(CCore::GetInst()->init(GetConsoleHwnd(), POINT{10, 30})))
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