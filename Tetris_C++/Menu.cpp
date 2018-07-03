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

	select = _getch() - '0';
	_getch();

	system("cls");

	return select;
}