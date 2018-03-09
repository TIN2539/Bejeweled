#pragma once
#include "Position.h"
#include "ConsoleLib.h"
#include "Level.h"

class Box
{
protected:
	Position pos_box;
	ConsoleColor color;
	int super_var;
public:
	Box();
	Box(int, int);
	Box(int, int, int);
	ConsoleColor GetColor();
	void ChangeColor(ConsoleColor);
	void Print();
	void SetSupervar(int);
	int GetSupervar();
};