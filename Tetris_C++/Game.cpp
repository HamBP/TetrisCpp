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
// 게임이 시작될 때 한 번 필요함. 생성자에 합쳐도 될 듯 하다.
void Game::start()
{
	level = INITIAL_LEVEL;
	bHandle->showMap();
	bHandle->makeBlock();
}
// 게임 실행에 대한 함수이다.
void Game::play()
{
	/* 이 변수가 참조되는 순간은 키보드 입력이 있을 때, 맵이 업데이트될 때임.*/
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

			/* 레벨에 따라 맵을 새로 그리기 전까지 대기할 시간. 밀리초. */
			int properDelayTimeForLevel = delay(level); 

			/* 현재 클럭 수를 가져옴. 전역 범위라 :: 써줌. */
			clock_t now = ::clock(); 

			int elapsed = (now - start) / 10;

			if (elapsed > properDelayTimeForLevel) {
				/*
				맵을 새로 그리는 아래 동작은 적정 시간이 지난 후에만 실행하며,
				실행 후에는 현재 시간을 기록해 놓음.
				*/
				cLine += bHandle->down();

				start = ::clock();
			}
			else {
				/*
				if와 continue를 사용하면 코드 실행 순서에 많은 제약을 받게 되므로, 
				추후 기능 확장과 유지보수를 위해 조건문을 그냥 사용함.
				*/
			}
			score += cLine * level;
			clearLine += cLine;
			cLine = 0;

			if (level < 20)	level = INITIAL_LEVEL + (clearLine / 10);		// 20 is max level
			showScore();
		}
	}
	catch (int over)
	{
		over;					// 경고 메시지 제거 용도
		showGameOver();
		Sleep(2000);
		bHandle->clearMap();
	}
}
// 게임 속도에 관한 함수이다.
int Game::delay(int level)
{
	int delay[20] = { 250, 180, 130, 145, 70, 50, 37, 27, 20, 15, 22, 17, 12, 9, 7, 5, 4, 3, 2, 1 };

	return (delay[level - 1]); // millis
}
// 게임오버 화면 출력
void Game::showGameOver()
{
	system("color 70");
	cout << "GAME OVER" << endl;
}
// 점수판 출력
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