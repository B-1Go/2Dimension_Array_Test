// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=soohan530&logNo=221017085392

#include <windows.h>
#include <stdio.h>

HANDLE hd;
DWORD fdwSaveOldMode;
DWORD dwNOER;

INPUT_RECORD irInBuf;

int main()
{
	hd = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(hd, &fdwSaveOldMode);

	DWORD fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hd, fdwMode);

	while (true)
	{
		ReadConsoleInput(hd, &irInBuf, 1, &dwNOER);

		if (irInBuf.EventType == MOUSE_EVENT)
		{// ���콺 �̺�Ʈ�� ���

			if (irInBuf.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
				int mouse_x = irInBuf.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
				int mouse_y = irInBuf.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

				printf("X : %d, Y : %d \n", mouse_x, mouse_y);
			}
		}
	}
	return 0;
}