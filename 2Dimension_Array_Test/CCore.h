#pragma once
#include "global.h"

class CCore
{
	SINGLE(CCore);
private:
	POINT m_ptInvenSize;
	HWND m_hWnd;

public:
	int init(HWND _hWnd, POINT _Size); // ������ �ػ� Resolution�ε� �ַܼ� �����ϴ� ���� ����ؼ� �κ������ â ũ���� �����սô�.
	void progress();

public:
	POINT GetInvenSize() { return m_ptInvenSize; }
	HWND GetMainHwnd() { return m_hWnd; }
};

