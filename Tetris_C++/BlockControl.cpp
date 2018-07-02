#include "BlockControl.h"
#include "block.h"
#include "map.h"

using namespace std;

BlockControl::BlockControl() 
{
	cur = { 0, 0 };
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}
bool BlockControl::isCollisionalToFloor()
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
void BlockControl::spin()
{
	cout << "spin";
}
void BlockControl::backSpin()
{
	cout << "backSpin";
}
void BlockControl::drop()
{
	cout << "drop";
}
void BlockControl::down()
{
	cur.Y++;
	if (isCollisionalToFloor()) {
		cur.Y--;
		exit(1);
	}
	eraseBlock();
	showBlock();
}
void BlockControl::moveLeft()
{
	cout << "left";
}
void BlockControl::moveRight()
{
	cout << "right";
}
void BlockControl::delay(int level)
{
	int delay[20] = {500, 360, 260, 190, 140, 100, 75, 55, 40, 30, 22, 17, 12, 9, 7, 5, 4, 3, 2, 1};

	Sleep(delay[level-1] * 10);
}
void BlockControl::showMap()
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
void BlockControl::showBlock()
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
void BlockControl::setBlock()
{
	blockType = 0;//rand() / 7;
	blockAngle = 0;
	cur.X = 8;
	cur.Y = 0;
}
void BlockControl::eraseBlock()
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
