#include "Game.h"

Game::Game() : clearLine(0), score(0)
{
	startT = (double)time(NULL);
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
	level = INITIAL_LEVEL;
	bHandle->showMap();
	bHandle->makeBlock();
}
void Game::play()
{
	/* �� ������ �����Ǵ� ������ Ű���� �Է��� ���� ��, ���� ������Ʈ�� ����.*/
	int cLine = 0;

	showScore();
	try
	{
		clock_t start = ::clock();
		while (true)
		{
			while (_kbhit())
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

			/* ������ ���� ���� ���� �׸��� ������ ����� �ð�. �и���. */
			int properDelayTimeForLevel = delay(level); 

			/* ���� Ŭ�� ���� ������. ���� ������ :: ����. */
			clock_t now = ::clock(); 


			//const int SPEED_CONSTANT = 2;
			int elapsed = (now - start) / 10;
			Sleep(5);

			if (elapsed > properDelayTimeForLevel) {
				/*
				���� ���� �׸��� �Ʒ� ������ ���� �ð��� ���� �Ŀ��� �����ϸ�,
				���� �Ŀ��� ���� �ð��� ����� ����.
				*/
				cLine += bHandle->down();
				clearLine += cLine;
				score += cLine * level;
				showScore();

				if (level < 20)	level = INITIAL_LEVEL + (clearLine / 10);		// 20 is max level

				cLine = 0;

				start = ::clock();
			}
			else {
				/*
				if�� continue�� ����ϸ� �ڵ� ���� ������ ���� ������ �ް� �ǹǷ�, 
				���� ��� Ȯ��� ���������� ���� ���ǹ��� �׳� �����.
				*/
			}
		}
	}
	catch (int over)
	{
		over;					// ��� �޽��� ���� �뵵
		showGameOver();
		Sleep(2000);
		bHandle->clearMap();
	}
}
int Game::delay(int level)
{
	int delay[20] = { 250, 180, 130, 145, 70, 50, 37, 27, 20, 15, 22, 17, 12, 9, 7, 5, 4, 3, 2, 1 };

	return (delay[level - 1]); // millis
}
void Game::showGameOver()
{
	system("color 70");
	cout << "GAME OVER" << endl;
}
void Game::showScore()
{
	double minute;
	double avg;
	minute = (time(NULL) - startT) / 60.0;
	avg = clearLine / minute;

	SetConsoleTextAttribute(handle, 2);
	SetConsoleCursorPosition(handle, { 30, 16 });
	cout << "Game Level      : " << level;
	SetConsoleCursorPosition(handle, { 30, 17 });
	cout << "Clear Line      : " << clearLine;
	SetConsoleCursorPosition(handle, { 30, 18 });
	printf("Line Per Minute : %lf ", avg);
	SetConsoleCursorPosition(handle, { 30, 19 });
	cout << "Score           : " << score;
}