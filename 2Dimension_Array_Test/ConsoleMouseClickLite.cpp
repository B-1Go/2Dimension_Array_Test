// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=soohan530&logNo=221017085392

#include <windows.h>
#include <stdio.h>

HANDLE hd;
DWORD fdwSaveOldMode;
DWORD dwNOER;

INPUT_RECORD irInBuf;

void init()
{
	hd = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(hd, &fdwSaveOldMode);

	DWORD fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hd, fdwMode);
}

void clear()
{
	system("cls");
	init();
}

int main()
{
	init();

	while (true)
	{
		ReadConsoleInput(hd, &irInBuf, 1, &dwNOER);

		if (irInBuf.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
		{
			if (irInBuf.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // 좌측 버튼이 클릭되었을 경우
				int mouse_x = irInBuf.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
				int mouse_y = irInBuf.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
				clear();
				printf("X : %d, Y : %d \n", mouse_x, mouse_y);
			}
		}
	}
	return 0;
}

