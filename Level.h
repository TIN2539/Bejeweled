#pragma once
#include <iostream>
#include "ConsoleLib.h"
using namespace std;

class Level
{
protected:
	int lvl;
	int score_lvl;
public:
	Level();
	int Getlvl();
	void UpLvl();
	int GetScore_lvl();
	void PrintLvl();
};

