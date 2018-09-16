#include "menu.h"

using namespace std;

int show_menu()
{
	int select = 1;
	COORD cur = {0, 0};
	Keyboard * kHandle = new Keyboard;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << "�������������� ���� ��� ��������������" << endl;
	cout << "������" << endl;				// 1
	cout << "�����̹�" << endl;				// 2
	cout << "�ΰ����ɰ� ���" << endl;		// 3
	cout << "�ٸ� ����� ���" << endl;		// 4
	cout << "����Ű ����(���� ����)" << endl;		// 5
	cout << "����" << endl;					// 6

	cout << endl << endl << "	����Ű" << endl << endl;
	cout << "���� �̵�       : �� " << endl;
	cout << "������ �̵�     : �� " << endl;
	cout << "�ð���� ȸ��   : �� " << endl;
	cout << "�ݽð���� ȸ�� : Z " << endl;
	cout << "�ϵ� ���       : space " << endl;
	cout << "����Ʈ ���     : �� " << endl;

	cout << endl << endl;
	cout << "��     ���� �߽߰�     ��" << endl;
	cout << "��  sjy_9484@naver.com ��" << endl;

	while (select < 10)
	{
		cur.Y = 1;
		SetConsoleCursorPosition(handle, cur);
		cout << "������" << endl;				// 1
		cout << "�����̹�" << endl;				// 2
		cout << "�ΰ����ɰ� ���" << endl;		// 3
		cout << "�ٸ� ����� ���" << endl;		// 4
		cout << "����Ű ����(���� ����)" << endl;		// 5
		cout << "����" << endl;					// 6

		cur.Y = select;

		switch (select) {
		case 1:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "������" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 2:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "�����̹�" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 3:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "�ΰ����ɰ� ���" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 4:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "�ٸ� ����� ���" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 5:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "����Ű ����(���� ����)" << endl;
			SetConsoleTextAttribute(handle, 0x70);
			break;
		case 6:
			SetConsoleCursorPosition(handle, cur);
			SetConsoleTextAttribute(handle, 0x07);
			cout << "����" << endl;
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
				// �ݺ��� Ż�� ����
				select += 10;
			}

		Sleep(20);
	}

	system("cls");

	return select - 10;
}