#include <iostream>
#include <time.h>
#include "Menu.h"
#include "BlockControl.h"
#include "Marathon.h"

using namespace std;

int main(void)
{
	int choice;
	
	while (true)
	{
		choice = show_menu();

		switch (choice) {
		case menu::marathon:
			Play_marathon();
			system("pause");
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