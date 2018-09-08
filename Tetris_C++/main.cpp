#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "Marathon.h"
		// 서바이벌 모드 업데이트 할 것
using namespace std;

int main(void)
{
	Game * game;
	int choice;							

#include "Setting.h"

	while (true)
	{
		choice = show_menu();

		switch (choice) {
		case menu::marathon:
			game = new Marathon();
			game->play();
			delete(game);
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