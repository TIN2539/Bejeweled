#pragma once
#include "Cursor.h"
#include "Level.h"
#include "ConsoleLib.h"

class Player
{
protected:
	char* name;
	int score;
public:
	Player();
	void ResetScore();
	void PrintPlayer();
	void ChangeScore(int);
	void PrintScore();
	int GetScore();

};

