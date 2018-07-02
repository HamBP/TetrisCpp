#pragma once

#include "BlockControl.h"
#include "Keyboard.h"

using namespace std;

class Game
{
private:
	BlockControl * bHandle;
	Keyboard * kHandle;
public:
	Game();
	~Game();
	void start();
	void play();
	bool isGameOver();
};