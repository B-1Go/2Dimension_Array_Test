#include "CCore.h"

#include "CKeyMgr.h"

CCore::CCore()
	: m_ptInvenSize{}
{
}
CCore::~CCore()
{
}

int CCore::init(POINT _Size)
{
	m_ptInvenSize = _Size;


	// Manager ÃÊ±âÈ­
	CKeyMgr::GetInst()->init();

	return S_OK;
}

void CCore::progress()
{
	CKeyMgr::GetInst()->update();
}
