#include "global.h"
#include "CCore.h"



int main()
{
	bool system_msg = false; // 커널 및 운영체제가 관여하는 부분을 압축적으로 표현

	if (FAILED(CCore::GetInst()->init(POINT{10, 30})))
	{
		MessageBox(nullptr, L"Core 객체 초기화 실패", L"ERROR", MB_OK);

		return FALSE;
	}

	while (true)
	{
		if (system_msg)
		{
			cout << "OS단에 메세지큐가 발생했습니다." << endl;
			system_msg = false;
		}
		else
		{
			CCore::GetInst()->progress();
		}
	}
}