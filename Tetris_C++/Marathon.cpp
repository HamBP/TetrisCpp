#include <iostream>
#include "Game.h"
// Game�� ��� �޾� Ŭ������ ���� ��
void Play_marathon()
{
	Game * game;

	game = new Game();

	game->start();
	game->play();

	delete(game);
}