#pragma once
#include "global.h"

class CCore
{
	SINGLE(CCore);
private:
	POINT m_ptInvenSize;

public:
	int init(POINT _Size); // ������ �ػ� Resolution�ε� �ַܼ� �����ϴ� ���� ����ؼ� �κ������ â ũ���� �����սô�.
	void progress();

public:
	POINT GetInvenSize() { return m_ptInvenSize; }

};

