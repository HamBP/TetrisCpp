#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdio>

class BlockControl
{
private:
	COORD cur;
	short gostY;
	HANDLE handle;
	int blockType;
	int blockAngle;
	bool isCollisionalToFloor();
	bool isCollisionalToFloorG();
	bool isCollisionalToLeft();
	bool isCollisionalToRight();
	int land();
	void eraseBlock();
	void eraseGostBlock();
	int checkLine();
	void clearLine(int);
	void dropLine(int);
public:
	BlockControl();
	~BlockControl();
	void spin();
	void backSpin();
	int drop();
	void gostDrop();
	void showGost();
	int down();
	void gostDown();
	int virtualDown();
	void moveLeft();
	void moveRight();
	void showMap();
	void showBlock(bool);
	void showNext(int, int);
	void makeBlock();
	bool isGameOver();
	void canSpin();
	void clearMap();
	int setBlock();
};