#pragma once
#include "global.h"

enum class KEY_STATE
{
	TAP, // �� ���� ����
	HOLD, // ������ �ִ� ����
	AWAY, // �� �� ����
	NONE, // ������ �ʰ�, �������� ������ ���� ����
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

	LBTN, // ���콺 ��Ŭ��
	RBTN, // ���콺 ��Ŭ��

	LAST,
};

struct tKeyInfo
{
	KEY_STATE eState; // Ű�� ���°�
	bool bPrevPush; // ���� �����ӿ��� ���ȴ��� ����
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();
};
