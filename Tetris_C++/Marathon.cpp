#include <iostream>
#include "BlockControl.h"

void Play_marathon()
{
	BlockControl blockHandle;

	blockHandle.Set_block();

	blockHandle.Show_block();

	while (true) {
		Sleep(500);
		blockHandle.Down();
	}
}