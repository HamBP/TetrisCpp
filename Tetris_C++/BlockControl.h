#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>
#include "block.h"
#include "map.h"

class BlockControl
{
private:
	COORD cur;
	HANDLE handle;
	int blockType;
	int blockAngle;
	//bool Is_collisional_to_floor();
public:
	BlockControl();
	bool Is_collisional_to_floor();
	void Spin_clockwise();
	void Spin_counterclockwise();
	void Drop();
	void Down();
	void Move_left();
	void Move_right();
	void Delay(int level);
	void Show_map();
	void Show_block();
	void Set_block();
	void Erase_block();
};