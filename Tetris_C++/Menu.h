#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Keyboard.h"

namespace menu {
	enum { marathon = 1, survival, AI, multiplayer, exit = 6 };
}

int show_menu();