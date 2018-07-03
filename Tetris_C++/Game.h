#pragma once

#include "BlockControl.h"
#include "Keyboard.h"

using namespace std;

class Game
{
private:
	HANDLE handle;
	BlockControl * bHandle;
	Keyboard * kHandle;
	int level;
	int clearLine;
	int score;
public:
	Game();
	~Game();
	void start();
	void play();
	void delay(int level);
	void showGameOver();
	virtual void showScore();
};