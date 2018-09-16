#pragma once

#include <conio.h>
#include <iostream>

enum { spin, down, moveLeft, moveRight, back, drop, enter };

class Keyboard
{
public:
	int input();
};

