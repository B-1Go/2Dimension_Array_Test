#pragma once

#include "global.h"

class CObject
{
private:
	wstring m_strName;

	fVec2 m_vPos;
	fVec2 m_vScale;

	bool m_bAlive;

public:
	void SetPos(fVec2 _vPos) { m_vPos = _vPos; }
	void SetScale(fVec2 _vScale) { m_vScale = _vScale; }

	fVec2 GetPos() { return m_vPos; }
	fVec2 GetScale() { return m_vScale; }
	iVec2 iGetPos() { return iVec2{(int)m_vPos.x, (int)m_vPos.y}; }
	iVec2 iGetScale() { return iVec2{ (int)m_vScale.x, (int)m_vScale.y }; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	bool IsDead() { return !m_bAlive; }

private:
	void SetDead() { m_bAlive = false; }

public:
	virtual void update() = 0;
	virtual void finalupdate() final;
	virtual void render();

	virtual CObject* Clone() = 0;


public:
	CObject();
	CObject(const CObject& _origin);
	virtual ~CObject();

	friend class CEventMgr;
};

