#include "global.h"
#include "CObject.h"

CObject::CObject()
	: m_vPos{}
	, m_vScale{}
	, m_bAlive(true)
{}

CObject::CObject(const CObject& _origin)
	: m_strName(_origin.m_strName)
	, m_vPos(_origin.m_vPos)
	, m_vScale(_origin.m_vScale)
	, m_bAlive(true)
{}

CObject::~CObject()
{
}

void CObject::finalupdate()
{

}

void CObject::render()
{

}