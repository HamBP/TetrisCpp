#pragma once

#include "BlockControl.h"
#include "Keyboard.h"

using namespace std;

class Game
{
private:
	BlockControl * bHandle;
	Keyboard * kHandle;
	int level;
public:
	Game();
	~Game();
	void start();
	void play();
	void delay(int level);
	bool isGameOver();
};