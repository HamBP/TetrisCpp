#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>

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
	bool isCollisionalToFloor();
	bool isCollisionalToLeft();
	bool isCollisionalToRight();
	void spin();
	void backSpin();
	void drop();
	void land();
	void down();
	void moveLeft();
	void moveRight();
	void showMap();
	void showBlock();
	void setBlock();
	void eraseBlock();
};