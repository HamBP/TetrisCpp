#include <iostream>
#include "BlockControl.h"

void Play_marathon()
{
	int level;
	BlockControl blockHandle;

	std::cout << "speed : ";
	std::cin >> level;
	system("cls");

	blockHandle.Show_map();
	blockHandle.Set_block();

	blockHandle.Show_block();

	while (true) {
		blockHandle.Delay(level);
		blockHandle.Down();
	}
}