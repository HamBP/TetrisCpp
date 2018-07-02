#include "BlockControl.h"

using namespace std;

BlockControl::BlockControl() 
{
	cur = { 0, 0 };
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}
bool BlockControl::Is_collisional_to_floor()
{
	int x;

	for (x = 0; x < 4; ++x) {
		if (map[cur.Y + 2][cur.X + x * 2] && block[blockType][blockAngle][2][x * 2])
			return true;
		if (map[cur.Y + 3][cur.X + x * 2] != 0 && block[blockType][blockAngle][3][x * 2])
			return true;
	}
	return false;
}
void BlockControl::Spin_clockwise()
{

}
void BlockControl::Spin_counterclockwise()
{

}
void BlockControl::Drop()
{

}
void BlockControl::Down()
{
	cur.Y++;
	if (Is_collisional_to_floor()) {
		cur.Y--;
		exit(1);
	}
	Erase_block();
	Show_block();
}
void BlockControl::Move_left()
{

}
void BlockControl::Move_right()
{

}
void BlockControl::Delay(int level)
{
	int delay[20] = {500, 360, 260, 190, 140, 100, 75, 55, 40, 30, 22, 17, 12, 9, 7, 5, 4, 3, 2, 1};

	Sleep(delay[level-1] * 10);
}
void BlockControl::Show_map()
{
	int x, y;

	cur.X = 0;
	cur.Y = 0;
	SetConsoleCursorPosition(handle, cur);

	for (y = 0; y < 21; ++y) {
		for (x = 0; x < 12; ++x)
			if (map[y][x * 2] == 9)
				cout << "бр";
			else
				cout << "  ";
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
}
void BlockControl::Show_block()
{
	int y, x;
	int empty = 0;

	SetConsoleCursorPosition(handle, cur);

	for (y = 0; y < 4; ++y) {
		for (x = 0; x < 4; ++x) {
			if (block[blockType][blockAngle][y][x] == 1)
				cout << "бс";
			else {
				cur.X += 2;
				empty += 2;
				SetConsoleCursorPosition(handle, cur);
			}
		}
		cur.X -= empty;
		empty = 0;
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
	cur.Y -= 4;
}
void BlockControl::Set_block()
{
	blockType = 0;//rand() / 7;
	blockAngle = 0;
	cur.X = 8;
	cur.Y = 0;
}
void BlockControl::Erase_block()
{
	int i, j;

	SetConsoleCursorPosition(handle, cur);

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j)
			cout << "  ";
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
	cur.Y -= 4;
}
