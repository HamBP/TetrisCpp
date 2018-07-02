#include <iostream>
#include <conio.h>
#include "menu.h"

using namespace std;

int show_menu()
{
	int select;

	cout << "┌──────────  MENU ──────────┐" << endl;
	cout << "│" << menu::marathon << ". 마라톤\t\t    │" << endl;
	cout << "│" << menu::survival << ". 서바이벌\t\t    │" << endl;
	cout << "│" << menu::AI << ". 인공지능과 대결\t    │" << endl;
	cout << "│" << menu::multiplayer << ". 다른 사람과 대결\t    │" << endl;
	cout << "│" << menu::exit << ". 종료\t\t    │" << endl;
	cout << "└───────────────────────────┘" << endl;

	select = _getch() - '0';
	_getch();

	system("cls");

	return select;
}