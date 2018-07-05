#include "Game.h"
						// 평균 속도 기능 추가하기 (블록, 라인)
Game::Game() : clearLine(0), score(0)
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
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
	level = 10;
	bHandle->showMap();
	bHandle->makeBlock();
	bHandle->showBlock();
}
void Game::play()
{
	int i;
	int cLine;

	try 
	{
		while (true)
		{
			for (i = 0; i < 10; ++i) {
				cLine = 0;
				delay(level);
				if (_kbhit())
					switch (kHandle->input()) {
					case spin:
						bHandle->spin();
						break;
					case down:
						cLine = bHandle->down();
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
						cLine = bHandle->drop();
						break;
					}
			}
			cLine += bHandle->down();
			clearLine += cLine;
			score += cLine * level;
			showScore();
			level = 10 + clearLine / 10;
		}
	}
	catch (int over)
	{
		over;					// 경고 메시지 제거 용도
		showGameOver();
		Sleep(2500);
	}
}
void Game::delay(int level)
{
	int delay[20] = { 500, 360, 260, 190, 140, 100, 75, 55, 40, 30, 22, 17, 12, 9, 7, 5, 4, 3, 2, 1 };

	Sleep(delay[level - 1]);
}
void Game::showGameOver()
{
	system("color 70");
	cout << "GAME OVER" << endl;
}
void Game::showScore()			// Marathon 클래스로 옮기는 게 적합함
{
	SetConsoleTextAttribute(handle, 2);
	SetConsoleCursorPosition(handle, { 30, 16 });
	cout << "Game Level : " << level << endl;
	SetConsoleCursorPosition(handle, { 30, 17 });
	cout << "Clear Line : " << clearLine << endl;
	SetConsoleCursorPosition(handle, { 30, 18 });
	cout << "Score      : " << score << endl;
}