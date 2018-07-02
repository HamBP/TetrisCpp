#pragma once

#include <windows.h>

class BlockControl
{
private:
	COORD cur;
	HANDLE handle;
	int blockType;
	int blockAngle;
	void Collision();
public:
	BlockControl();
	void Spin_clockwise();
	void Spin_counterclockwise();
	void Drop();
	void Down();
	void Move_left();
	void Move_right();
	void Deley();
	void Show_map();
	void Show_block();
	void Set_block();
	void Erase_block();
	void Show_map();
};