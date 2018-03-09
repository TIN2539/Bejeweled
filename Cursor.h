#pragma once
#include "Position.h"
#include "ConsoleLib.h"
#include "Board.h"

class Cursor
{
protected:
	Position curs_pos;
	bool choise;
public:
	Cursor();
	void MoveCursor(int);
	bool GetChoise();
	void SetChoise(bool);
	void PrintCursorDefault();
	void PrintCursorChoise();
	void CleanCursor();
	Position Getpos();
};

