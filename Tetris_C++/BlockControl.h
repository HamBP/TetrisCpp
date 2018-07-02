#pragma once

#include <windows.h>

class BlockControl
{
private:
	COORD cur;
	void Collision();
public:
	BlockControl() : cur({ 10, 0 }) {}
	void Spin_clockwise();
	void Spin_counterclockwise();
	void Drop();
	void Down();
	void Move_left();
	void Move_right();
	void Deley();
	void Show_map();
	void Show_block();
};