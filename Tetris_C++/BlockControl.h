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
	int land();
	void eraseBlock();
	int checkLine();
	void clearLine(int y);
	void dropLine(int y);
public:
	BlockControl();
	void spin();
	void backSpin();
	int drop();
	int down();
	void moveLeft();
	void moveRight();
	void showMap();
	void showBlock();
	void setBlock();
	bool isGameOver();
};