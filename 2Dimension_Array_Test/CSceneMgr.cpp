#include "CSceneMgr.h"

#include "CMainScene.h"

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	// �� ���� ����
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		// ��� ���� ä������ �ƴ� (�����ڿ��� �� ������ nullptr�� ä���� ������ delete ���� ó����)
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

	// ����� ����
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