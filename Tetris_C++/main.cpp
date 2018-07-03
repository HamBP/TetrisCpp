#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "Marathon.h"
		// 서바이벌 모드 업데이트 할 것
using namespace std;

int main(void)
{
	int choice;											
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);	// 함수로 묶어서 처리할 것
	CONSOLE_CURSOR_INFO cursor;
	
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(handle, &cursor);

	system("title Tetris (https://sjy_9484.blog.me/)");
	system("color 70");
	system("mode con: cols=50 lines=25");

	while (true)
	{
		choice = show_menu();

		switch (choice) {
		case menu::marathon:
			Play_marathon();
			break;
		case menu::survival:
			cout << "준비중입니다. " << endl;
			system("pause");
			break;
		case menu::AI:
			cout << "준비중입니다. " << endl;
			system("pause");
			break;
		case menu::multiplayer:
			cout << "준비중입니다. " << endl;
			system("pause");
			break;
		case menu::exit:
			cout << "게임을 종료합니다." << endl;
			return 0;
		default:
			cout << "error!!" << endl;
		}
		
		system("cls");
	}

	return -1;
}