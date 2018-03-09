#pragma once
#include "Board.h"
#include "Cursor.h"
#include "Level.h"
#include "Player.h"
#include "Box.h"
#include <iostream>
#include <fstream>
using namespace std;

extern const int Enter;
extern const int Esc;

class Game
{
	Player pl;
	Cursor pl_curs;
	Board pl_board;
	Level pl_lvl;
public:
	bool RemoveBox();
	void RemoveSomeBox(int, int, int, int);
	void SuperRemove(int, int);
	bool CheckMove();
	void Print();
	void GameProcces(int);
	void ForStart();
	void Swap(int, int, int, int);
	bool CheckWin();
	//void SaveToFile();
	//Game LoadFromFile();
};

