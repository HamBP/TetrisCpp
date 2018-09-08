#pragma once

#include "BlockControl.h"
#include "Keyboard.h"

#define INITIAL_LEVEL 1

using namespace std;

class Game
{
private:
	HANDLE handle;
	BlockControl * bHandle;
	Keyboard * kHandle;
	int level;
	int clearLine;
	float linePerM;
	int score;
	int next;
	double startT;
public:
	Game();
	~Game();
	void start();
	virtual void play();
	int delay(int level);
	void showGameOver();
	virtual void showScore();
};