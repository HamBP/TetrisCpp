#include "BlockControl.h"
#include "Block.h"
#include "Map.h"
							// next 기능 추가하기
using namespace std;

BlockControl::BlockControl() : gostY(0)
{
	cur = { 0, 0 };
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	blockType = 0;
	blockAngle = 0;
	srand((int)time(NULL));
}
BlockControl::~BlockControl()
{
	clearMap();
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
	showBlock(true);
}
void BlockControl::backSpin()
{
	eraseBlock();
	blockAngle += 3;
	blockAngle %= 4;
	canSpin();
	showBlock(true);
}
int BlockControl::drop()
{
	eraseBlock();

	while (!isCollisionalToFloor())
		virtualDown();

	return land();
}
void BlockControl::gostDrop()
{
	gostY = cur.Y;

	while (!isCollisionalToFloorG())
		gostDown();
}
bool BlockControl::isCollisionalToFloorG()
{
	int x;

	for (x = 0; x < 4; ++x)
	{
		if (map[gostY + 2][cur.X + x * 2] && block[blockType][blockAngle][1][x])
			return true;
		if (map[gostY + 3][cur.X + x * 2] && block[blockType][blockAngle][2][x])
			return true;
		if (map[gostY + 4][cur.X + x * 2] && block[blockType][blockAngle][3][x])
			return true;
	}

	return false;
}
void BlockControl::gostDown()
{
	gostY++;
}
void BlockControl::showGost()
{
	gostDrop();
	showBlock(false);
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
	makeBlock();
	showBlock(true);

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
	showBlock(true);

	return 0;
}
int BlockControl::virtualDown()
{
	if (isCollisionalToFloor())
		return land();

	cur.Y++;
	
	return 0;
}
void BlockControl::moveLeft()
{
	if (isCollisionalToLeft())
		return;

	eraseBlock();
	cur.X -= 2;
	showBlock(true);
}
void BlockControl::moveRight()
{
	if (isCollisionalToRight())
		return;

	eraseBlock();
	cur.X += 2;
	showBlock(true);
}
void BlockControl::showMap()
{
	int x, y;

	cur.X = 0;
	cur.Y = 0;
	SetConsoleCursorPosition(handle, cur);

	for (y = 0; y < 23; ++y) {
		for (x = 0; x < 28; x += 2)
			if (map[y][x] == 9) {
				SetConsoleTextAttribute(handle, map[y][x]);
				printf("□");
			}
			else if (map[y][x]) {
				SetConsoleTextAttribute(handle, map[y][x] - 9);
				printf("■");
			}
			else
				printf("  ");
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
}
void BlockControl::showBlock(bool real)
{
	int y, x;

	if (real)
	{
		showGost();
		SetConsoleCursorPosition(handle, cur);

		for (y = 0; y < 4; ++y) {
			for (x = 0; x < 4; ++x) {
				if (block[blockType][blockAngle][y][x]) {
					SetConsoleTextAttribute(handle, blockType + 1);
					printf("■");
				}
				else {
					if (map[cur.Y][cur.X + x * 2] == 9) {
						SetConsoleTextAttribute(handle, map[cur.Y][cur.X + x * 2]);
						printf("□");
					}
					else if (map[cur.Y][cur.X + x * 2]) {
						SetConsoleTextAttribute(handle, map[cur.Y][cur.X + x * 2] - 9);
						printf("■");
					}
					else // 고스트 오버랩 되는 지점
						printf("  ");
				}
			}
			cur.Y++;
			SetConsoleCursorPosition(handle, cur);
		}
		cur.Y -= 4;
	}
	else
	{
		SetConsoleCursorPosition(handle, { cur.X, gostY });

		for (y = 0; y < 4; ++y) {
			for (x = 0; x < 4; ++x) {
				if (block[blockType][blockAngle][y][x]) {
					SetConsoleTextAttribute(handle, blockType + 1);
					printf("▨");
				}
				else {
					if (map[gostY][cur.X + x * 2] == 9) {
						SetConsoleTextAttribute(handle, map[gostY][cur.X + x * 2]);
						printf("□");
					}
					else if (map[gostY][cur.X + x * 2]) {
						SetConsoleTextAttribute(handle, map[gostY][cur.X + x * 2] - 9);
						printf("■");
					}
					else
						printf("  ");
				}
			}
			gostY++;
			SetConsoleCursorPosition(handle, { cur.X, gostY });
		}
		gostY -= 4;
	}
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

	eraseGostBlock();
}
void BlockControl::eraseGostBlock()
{
	int x, y;

	SetConsoleCursorPosition(handle, { cur.X, gostY });

	for (y = 0; y < 4; ++y)
	{
		for (x = 0; x < 4; ++x)
			if (map[gostY][cur.X + x * 2] == 9) {
				SetConsoleTextAttribute(handle, map[gostY][cur.X + x * 2]);
				cout << "□";
			}
			else if (map[gostY][cur.X + x * 2]) {
				SetConsoleTextAttribute(handle, map[gostY][cur.X + x * 2] - 9);
				cout << "■";
			}
			else
				cout << "  ";

		gostY++;
		SetConsoleCursorPosition(handle, {cur.X, gostY});
	}
}
void BlockControl::showNext(int n1, int n2)
{
	short x, y;

	SetConsoleCursorPosition(handle, {28, 0});

	for (y = 0; y < 4; ++y) {
		for (x = 0; x < 4; ++x) {
			if (block[n1][0][y][x]) {
				SetConsoleTextAttribute(handle, n1 + 1);
				printf("■");
			}
			else
				printf("  ");
		}
		cur.Y++;
		SetConsoleCursorPosition(handle, { 28, y + 1 });
	}
	SetConsoleTextAttribute(handle, 9);
	printf("□□□□");
	SetConsoleCursorPosition(handle, { 28, 5 });
	for (y = 0; y < 4; ++y) {
		for (x = 0; x < 4; ++x) {
			if (block[n2][0][y][x]) {
				SetConsoleTextAttribute(handle, n2 + 1);
				printf("■");
			}
			else
				printf("  ");
		}
		cur.Y++;
		SetConsoleCursorPosition(handle, { 28, y + 6 });
	}
	SetConsoleTextAttribute(handle, 9);
	printf("□□□□");
}
void BlockControl::makeBlock()
{
	static int cBlock[3] = {0, setBlock(), setBlock()};
	int i;

	for (i = 0; i < 2; ++i)
		cBlock[i] = cBlock[i + 1];
	cBlock[2] = setBlock();
	blockType = cBlock[0];
	
	showNext(cBlock[1], cBlock[2]);
	
	blockAngle = 0;
	cur.X = 10;
	cur.Y = 0;
	showBlock(true);
}
int BlockControl::setBlock()
{
	static int rotation[7];
	static int bCur = 0;
	int blockT;
	int i;
	
	if (bCur == 7)
		bCur = 0;

	blockT = rand() % 7;

	for (i = 0; i < bCur; ++i)			// 다양한 블록이 나오도록 하는 알고리즘
		if (blockT == rotation[i])		// 이번 로테이션에 같은 블록이 나왔다면
		{
			i = -1;
			blockT = rand() % 7;		// 블록 재설정
		}

	rotation[bCur] = blockT;
	bCur++;

	return blockT;
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
void BlockControl::clearMap()
{
	int y, x;

	for (y = 1; y < 21; ++y)
		for (x = 2; x < 12; ++x)
			map[y][x * 2] = 0;
}