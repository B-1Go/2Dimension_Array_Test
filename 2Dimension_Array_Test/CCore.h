#pragma once
#include "global.h"

class CCore
{
	SINGLE(CCore);
private:
	POINT m_ptInvenSize;
	HWND m_hWnd;

public:
	int init(HWND _hWnd, POINT _Size); // 원래는 해상도 Resolution인데 콘솔로 구현하는 점을 고려해서 인벤사이즈가 창 크기라고 생각합시다.
	void progress();

public:
	POINT GetInvenSize() { return m_ptInvenSize; }
	HWND GetMainHwnd() { return m_hWnd; }
};

