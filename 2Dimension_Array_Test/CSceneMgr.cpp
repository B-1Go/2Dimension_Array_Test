#include "CSceneMgr.h"

#include "CMainScene.h"

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	// 씬 전부 삭제
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		// 모든 씬이 채워진게 아님 (생성자에서 빈 공간은 nullptr로 채웠기 때문에 delete 예외 처리함)
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneMgr::init()
{
	m_arrScene[(UINT)SCENE_TYPE::START] = new CMainScene;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Main Scene");

	// 현재씬 지정
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();
}

void CSceneMgr::render()
{
	m_pCurScene->render();
}