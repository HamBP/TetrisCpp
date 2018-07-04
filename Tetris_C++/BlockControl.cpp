#include "BlockControl.h"
#include "Block.h"
#include "Map.h"
							// next 기능 추가하기, drop 최적화하기
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
	canSpin();
	showBlock();
}
void BlockControl::backSpin()
{
	eraseBlock();
	blockAngle += 3;
	blockAngle %= 4;
	canSpin();
	showBlock();
}
int BlockControl::drop()
{
	int line = 0;

	while (!isCollisionalToFloor())
		line = down();

	return line;
}
int BlockControl::land()
{
	int x, y;
	int line;

	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x) 
			if (block[blockType][blockAngle][y][x] != 0)
				map[cur.Y + y][cur.X + x * 2] = blockType + 10;
		
	line = checkLine();
	showMap();
	setBlock();
	if (isGameOver())
		throw (0);

	return line;
}
int BlockControl::down()
{
	if (isCollisionalToFloor())
		return land();

	eraseBlock();
	cur.Y++;
	showBlock();

	return 0;
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

	for (y = 0; y < 23; ++y) {
		for (x = 0; x < 14; ++x)
			if (map[y][x * 2] == 9) {
				SetConsoleTextAttribute(handle, map[y][x * 2]);
				cout << "□";
			}
			else if (map[y][x * 2]) {
				SetConsoleTextAttribute(handle, map[y][x * 2] - 9);
				cout << "■";
			}
			else
				cout << "  ";
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
}
void BlockControl::showBlock()
{
	int y, x;

	SetConsoleCursorPosition(handle, cur);

	for (y = 0; y < 4; ++y) {
		for (x = 0; x < 4; ++x) {
			if (block[blockType][blockAngle][y][x]) {
				SetConsoleTextAttribute(handle, blockType + 1);
				cout << "■";
			}
			else {
				if (map[cur.Y][cur.X + x * 2] == 9) {
					SetConsoleTextAttribute(handle, map[cur.Y][cur.X + x * 2]);
					cout << "□";
				}
				else if (map[cur.Y][cur.X + x * 2]) {
					SetConsoleTextAttribute(handle, map[cur.Y][cur.X + x * 2] - 9);
					cout << "■";
				}
				else
					cout << "  ";
			}
		}
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
	cur.Y -= 4;
}
void BlockControl::setBlock()
{
	blockType = rand() % 7;
	blockAngle = 0;
	cur.X = 10;
	cur.Y = 0;
	showBlock();
}
void BlockControl::eraseBlock()
{
	int x, y;

	SetConsoleCursorPosition(handle, cur);

	for (y = 0; y < 4; ++y) 
	{
		for (x = 0; x < 4; ++x)
			if (map[cur.Y][cur.X + x * 2] == 9) {
				SetConsoleTextAttribute(handle, map[cur.Y][cur.X + x * 2]);
				cout << "□";
			}
			else if (map[cur.Y][cur.X + x * 2]) {
				SetConsoleTextAttribute(handle, map[cur.Y][cur.X + x * 2] - 9);
				cout << "■";
			}
			else
				cout << "  ";
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
	cur.Y -= 4;
}
int BlockControl::checkLine()
{
	int x, y;
	int line = 0;

	for (y = 20; y > 0 + line; --y)
		for (x = 4; x < 24; x += 2)
		{
			if (!map[y + line][x])
				break;

			if (x == 22) {
				clearLine(y + line);
				line++;
			}
		}

	return line;
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

	for (x = 4; x < 24; x += 2)
		map[y+1][x] = map[y][x];
}
bool BlockControl::isGameOver()
{
	int x, y;

	for (y = 1; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			if (block[blockType][blockAngle][y][x] && map[cur.Y + y][cur.X + x * 2])
				return true;

	return false;
}
void BlockControl::canSpin()				// 예외 상황이 많음, T스핀이나 회전 불가능한 경우도 고려해 업데이트 필요
{
	int x, y;

	for (y = 1; y < 3; ++y)					// 가로로 삽입 됐을 경우
		for (x = 0; x < 4; x += 3)
			if (block[blockType][blockAngle][y][x] && map[cur.Y + y][cur.X + x * 2]) 
				cur.X += x ? (-2) : (2);	// 왼쪽으로 삽입 됐을 경우 오른쪽으로 이동, 반대의 경우엔 반대 방향으로
			
	if (blockType == 1)						// 1자 모양 블록일 때 2칸 깊이로 삽입되는 경우를 고려
		for (y = 1; y < 3; ++y)
			for (x = 0; x < 4; x += 3)
				if (block[blockType][blockAngle][y][x] && map[cur.Y + y][cur.X + x * 2])
					cur.X += x ? (-2) : (2);

	for (x = 1; x < 3; ++x)					// 세로로 삽입 됐을 경우
		for (y = 2; y < 4; ++y)
			if (block[blockType][blockAngle][y][x] && map[cur.Y + y][cur.X + x * 2])
				cur.Y--;
}