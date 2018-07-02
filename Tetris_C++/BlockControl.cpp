#include <iostream>
#include <ctime>
#include "BlockControl.h"
#include "block.h"
#include "map.h"

using namespace std;

BlockControl::BlockControl() 
{
	cur = { 8, 0 };
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}
void BlockControl::Collision()
{

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
	Erase_block();
	cur.Y++;
	Show_block();
}
void BlockControl::Move_left()
{

}
void BlockControl::Move_right()
{

}
void BlockControl::Deley()
{

}
void BlockControl::Show_map()
{

}
void BlockControl::Show_block()
{
	int i, j;
	
	SetConsoleCursorPosition(handle, cur);

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j)
			if (block[blockType][blockAngle][i][j] == 1)
				cout << "бс";
			else
				cout << "  ";
		cur.Y++;
		SetConsoleCursorPosition(handle, cur);
	}
	cur.Y -= 4;
}
void BlockControl::Set_block()
{
	blockType = rand() / 7;
	blockAngle = 0;
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