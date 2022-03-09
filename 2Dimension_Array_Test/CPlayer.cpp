#include "global.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CkeyMgr.h"
#include "CTimeMgr.h"

#include "CCore.h"

CPlayer::CPlayer()
	: click_toggle(false)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::consoleinit()
{
	hd = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(hd, &fdwSaveOldMode);

	DWORD fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hd, fdwMode);
}

void CPlayer::update()
{
	fVec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 1 * fDT;
	}

	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 1 * fDT;
	}

	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 1 * fDT;
	}

	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 1 * fDT;
	}

	if (KEY_TAP(KEY::LBTN))
	{
		if (false == click_toggle)
		{
			printf("ON");
			click_toggle = true;
		}
		else
		{
			printf("OFF");
			click_toggle = false;
		}
	}



	if (true == click_toggle)
	{
		click_toggle = true;
	}

	SetPos(vPos);
}

void CPlayer::render()
{
	iVec2 vPos = iGetPos();

	if (true == click_toggle)
	{
		consoleinit();
		ReadConsoleInput(hd, &irInBuf, 1, &dwNOER);
		int mouse_x = irInBuf.Event.MouseEvent.dwMousePosition.X; // X°ª ¹Þ¾Æ¿È
		int mouse_y = irInBuf.Event.MouseEvent.dwMousePosition.Y; // Y°ª ¹Þ¾Æ¿È
		system("cls");
		printf("X : %d, Y : %d \n", mouse_x, mouse_y);
	}

	//printf("X : %d, Y : %d \n", vPos.x, vPos.y);
}

