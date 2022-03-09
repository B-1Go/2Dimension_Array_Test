#pragma once
#include "global.h"

class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);
private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END]; // ¸ðµç ¾À ¸ñ·Ï
	CScene* m_pCurScene; // ÇöÀç ¾À

public:
	void init();
	void update();
	void render();

public:
	CScene* GetCurScene() { return m_pCurScene; };

};

