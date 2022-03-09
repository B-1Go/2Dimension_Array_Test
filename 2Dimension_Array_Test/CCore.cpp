#include "global.h"
#include "CCore.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"

CCore::CCore()
	: m_ptInvenSize{}
{
}
CCore::~CCore()
{
}

int CCore::init(HWND _hWnd, POINT _Size)
{
	m_ptInvenSize = _Size;
	m_hWnd = _hWnd;

	// Manager ÃÊ±âÈ­
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();
	

	return S_OK;
}

void CCore::progress()
{
	// Manager update
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CSceneMgr::GetInst()->update();


	// rendering
	CSceneMgr::GetInst()->render();

	CTimeMgr::GetInst()->render();
}
