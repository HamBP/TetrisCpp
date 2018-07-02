#include "Game.h"

Game::Game()
{
	bHandle = new BlockControl();
	kHandle = new Keyboard();
}
Game::~Game()
{
	delete bHandle;
	delete kHandle;
}
void Game::start()
{
	level = 7;
	bHandle->showMap();
	bHandle->setBlock();
	bHandle->showBlock();
}
void Game::play()
{
	int i;

	while (!isGameOver())
	{
		for (i = 0; i < 10; ++i) {
			delay(level);
			if (_kbhit())
				switch (kHandle->input()) {
				case spin:
					bHandle->spin();
					break;
				case down:
					bHandle->down();
					break;
				case moveLeft:
					bHandle->moveLeft();
					break;
				case moveRight:
					bHandle->moveRight();
					break;
				case back:
					bHandle->backSpin();
					break;
				case drop:
					bHandle->drop();
					break;
				}
		}
			bHandle->down();
	}
}
void Game::delay(int level)
{
	int delay[20] = { 500, 360, 260, 190, 140, 100, 75, 55, 40, 30, 22, 17, 12, 9, 7, 5, 4, 3, 2, 1 };

	Sleep(delay[level - 1]);
}

bool Game::isGameOver()
{
	return false;
}