#include "global.h"
#include "CMainScene.h"

#include "CPlayer.h"
#include "CObject.h"
#include "CCore.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"


CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

void CMainScene::update()
{
	CScene::update();
}

void CMainScene::Enter()
{
	CObject* pObj = new CPlayer;
	pObj->SetPos(fVec2(0,0));
	pObj->SetScale(fVec2(1, 1));
	AddObject(pObj, GROUP_TYPE::PLAYER);
}

void CMainScene::Exit()
{
	DeleteAll();
}

