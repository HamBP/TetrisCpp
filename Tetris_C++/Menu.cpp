#include <iostream>
#include <conio.h>
#include "menu.h"

using namespace std;

int show_menu()
{
	int select;

	cout << "����������������������  MENU ����������������������" << endl;
	cout << "��" << menu::marathon << ". ������\t\t    ��" << endl;
	cout << "��" << menu::survival << ". �����̹�\t\t    ��" << endl;
	cout << "��" << menu::AI << ". �ΰ����ɰ� ���\t    ��" << endl;
	cout << "��" << menu::multiplayer << ". �ٸ� ����� ���\t    ��" << endl;
	cout << "��" << menu::exit << ". ����\t\t    ��" << endl;
	cout << "����������������������������������������������������������" << endl;

	select = _getch() - '0';
	_getch();

	system("cls");

	return select;
}