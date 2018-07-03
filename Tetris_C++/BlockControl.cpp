#include "BlockControl.h"
#include "Block.h"
#include "Map.h"

using namespace std;

BlockControl::BlockControl() 
{
	cur = { 0, 0 };
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	blockType = 0;
	blockAngle = 0;
	srand((int)time(NULL));
}
bool BlockControl::isCollisionalToFloor()
{
	int x;

	for (x = 0; x < 4; ++x) 
	{
		if (map[cur.Y + 2][cur.X + x * 2] && block[blockType][blockAngle][1][x])
			return true;
		if (map[cur.Y + 3][cur.X + x * 2] && block[blockType][blockAngle][2][x])
			return true;
		if (map[cur.Y + 4][cur.X + x * 2] && block[blockType][blockAngle][3][x])
			return true;
	}
	return false;
}
bool BlockControl::isCollisionalToLeft()
{
	int y;

	for (y = 0; y < 4; ++y) 
	{
		if (map[cur.Y + y][cur.X - 2] && block[blockType][blockAngle][y][0])
			return true;
		if (map[cur.Y + y][cur.X] && block[blockType][blockAngle][y][1])
			return true;
		if (map[cur.Y + y][cur.X + 2] && block[blockType][blockAngle][y][2])
			return true;
	}
	return false;
}
bool BlockControl::isCollisionalToRight()
{
	int y;

	for (y = 0; y < 4; ++y) {
		if (map[cur.Y + y][cur.X + 8] && block[blockType][blockAngle][y][3])
			return true;
		if (map[cur.Y + y][cur.X + 6] && block[blockType][blockAngle][y][2])
			return true;
		if (map[cur.Y + y][cur.X + 4] && block[blockType][blockAngle][y][1])
			return true;
	}
	return false;
}
void BlockControl::spin()
{
	eraseBlock();
	blockAngle++;
	blockAngle %= 4;
	showBlock();
}
void BlockControl::backSpin()
{
	eraseBlock();
	blockAngle += 3;
	blockAngle %= 4;
	showBlock();
}
void BlockControl::drop()
{
	eraseBlock();
	
	while (!isCollisionalToFloor())
		down();
}
void BlockControl::land()
{
	int x, y;

	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x) 
			if (block[blockType][blockAngle][y][x] != 0)
				map[cur.Y + y][cur.X + x * 2] = blockType + 10;
		
	checkLine();
	showMap();
	setBlock();
	showBlock();
}
void BlockControl::down()
{
	if (isCollisionalToFloor()) {
		land();
		return;
	}
	eraseBlock();
	cur.Y++;
	showBlock();
}
void BlockControl::moveLeft()
{
	if (isCollisionalToLeft())
		return;

	eraseBlock();
	cur.X -= 2;
	showBlock();
}
void BlockControl::moveRight()
{
	if (isCollisionalToRight())
		return;

	eraseBlock();
	cur.X += 2;
	showBlock();
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
			else if (map[y][x * 2])
				cout << "бс";
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
	//SetConsoleTextAttribute(handle, blockType);

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
	blockType = rand() % 7;
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
void BlockControl::checkLine()
{
	int x, y;
	int line = 0;

	for (y = 19; y > 0 + line; --y)
		for (x = 2; x < 22; x += 2)
		{
			if (!map[y + line][x])
				break;

			if (x == 20) {
				clearLine(y + line);
				line++;
			}
		}
}
void BlockControl::clearLine(int y)
{
	int dropY;

	for (dropY = y - 1; dropY > 0; --dropY)
		dropLine(dropY);
}
void BlockControl::dropLine(int y)
{
	int x;

	for (x = 2; x < 22; x += 2)
		map[y+1][x] = map[y][x];
}