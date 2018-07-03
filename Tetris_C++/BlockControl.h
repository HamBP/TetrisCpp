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
	bool isCollisionalToFloor();
	bool isCollisionalToLeft();
	bool isCollisionalToRight();
public:
	BlockControl();
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
	void checkLine();
	void clearLine(int y);
	void dropLine(int y);
};