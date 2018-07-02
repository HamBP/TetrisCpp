#include <iostream>
#include "BlockControl.h"
#include "block.h"

using namespace std;

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

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j)
			if (block[3][0][i][j] == 1)
				cout << "бс";
			else
				cout << "  ";
		cout << endl;
	}

	/*
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, cur);
	std::cout << 123 << std::endl;*/
}