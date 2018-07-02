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
	bHandle->showMap();
	bHandle->setBlock();
	bHandle->showBlock();
}
void Game::play()
{
	while (!isGameOver())
	{
		bHandle->delay(5);
		bHandle->down();
		if (_kbhit()) 
		{
			switch (kHandle->input()) {
			case spin:
				bHandle->spin();
			case down:
				bHandle->down();
			case moveLeft:
				bHandle->moveLeft();
			case moveRight:
				bHandle->moveRight();
			case back:
				bHandle->backSpin();
			case drop:
				bHandle->drop();
			}
		}
	}
}

bool Game::isGameOver()
{
	return false;
}