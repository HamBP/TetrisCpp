#include "menu.h"

using namespace std;

int show_menu()
{
	int select = 1;
	COORD cur = {0, 0};
	Keyboard * kHandle = new Keyboard;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << "─────── 게임 모드 ───────" << endl;
	cout << "마라톤" << endl;				// 1
	cout << "서바이벌" << endl;				// 2
	cout << "인공지능과 대결" << endl;		// 3
	cout << "다른 사람과 대결" << endl;		// 4
	cout << "조작키 설명(선택 금지)" << endl;		// 5
	cout << "종료" << endl;					// 6

	cout << endl << endl << "	조작키" << endl << endl;
	cout << "왼쪽 이동       : ← " << endl;
	cout << "오른쪽 이동     : → " << endl;
	cout << "시계방향 회전   : ↑ " << endl;
	cout << "반시계방향 회전 : Z " << endl;
	cout << "하드 드랍       : space " << endl;
	cout << "소프트 드랍     : ↓ " << endl;

	cout << endl << endl;
	cout << "┌     버그 발견시     ┐" << endl;
	cout << "└  sjy_9484@naver.com ┘" << endl;

	while (select < 10)
	{
		cur.Y = 1;
		SetConsoleCursorPosition(handle, cur);
		cout << "마라톤" << endl;				// 1
		cout << "서바이벌" << endl;				// 2
		cout << "인공지능과 대결" << endl;		// 3
		cout << "다른 사람과 대결" << endl;		// 4
		cout << "조작키 설명(선택 금지)" << endl;		// 5
		cout << "종료" << endl;					// 6

		cur.Y = select;

		switch (select) {
		case 1:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "마라톤" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 2:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "서바이벌" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 3:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "인공지능과 대결" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 4:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "다른 사람과 대결" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 5:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "조작키 설명(선택 금지)" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 6:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "종료" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		}

		while (_kbhit())
			switch (kHandle->input()) {
			case spin:
				if (select > 1)	select--;
				break;
			case down:
				if (select < 6)	select++;
				break;
			case drop:
			case enter:
				// 반복문 탈출 조건
				select += 10;
			}

		Sleep(20);
	}

	system("cls");

	return select - 10;
}