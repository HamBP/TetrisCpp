#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "Marathon.h"
		// �����̹� ��� ������Ʈ �� ��
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