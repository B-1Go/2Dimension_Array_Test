#pragma once
#include "global.h"

enum class KEY_STATE
{
	TAP, // 막 누른 시점
	HOLD, // 누르고 있는 시점
	AWAY, // 막 뗀 시점
	NONE, // 눌리지 않고, 이전에도 눌리지 않은 상태
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LBTN, // 마우스 왼클릭
	RBTN, // 마우스 우클릭

	LAST,
};

struct tKeyInfo
{
	KEY_STATE eState; // 키의 상태값
	bool bPrevPush; // 이전 프레임에서 눌렸는지 여부
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
};

