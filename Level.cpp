#include "Level.h"

Level::Level()
{
	lvl = 0;
	score_lvl = 30;
}

int Level :: Getlvl()
{
	return lvl;
}

void Level::UpLvl()
{
	++lvl;
	score_lvl *= 2;
}

int Level::GetScore_lvl()
{
	return score_lvl;
}

void Level::PrintLvl()
{
	ChangeTextAttr(47, 2, Black, Black, 25);
	WriteStr(40, 2, "Level: ");
	cout << lvl;
}