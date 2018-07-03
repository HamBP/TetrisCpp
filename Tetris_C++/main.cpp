#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "Marathon.h"
		// �����̹� ��� ������Ʈ �� ��
using namespace std;

int main(void)
{
	int choice;											
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);	// �Լ��� ��� ó���� ��
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
			cout << "�غ����Դϴ�. " << endl;
			system("pause");
			break;
		case menu::AI:
			cout << "�غ����Դϴ�. " << endl;
			system("pause");
			break;
		case menu::multiplayer:
			cout << "�غ����Դϴ�. " << endl;
			system("pause");
			break;
		case menu::exit:
			cout << "������ �����մϴ�." << endl;
			return 0;
		default:
			cout << "error!!" << endl;
		}
		
		system("cls");
	}

	return -1;
}