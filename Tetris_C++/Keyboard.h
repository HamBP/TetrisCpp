#pragma once

#include <conio.h>
#include <iostream>

enum { spin, down, moveLeft, moveRight, back, drop };

class Keyboard
{
public:
	int input();
};

