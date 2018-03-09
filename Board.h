#pragma once
#include <vector>
#include "Box.h"
#include <iostream>
#include "ConsoleLib.h"
#include <time.h>
#include <conio.h>
using namespace std;

class Board
{
protected:
	vector<vector<Box*>> vect;
public:
	Board();
	void newBoard(int);
	void StartBoard();
	bool CompareBox(int, int, int, int);
	vector<vector<Box*>> Getvect();
	void PrintBoard();
	void PrintGrani();
	bool CheckSwap(int, int, int, int);
	bool CheckCombination(int, int, int, int);
	void VisualHorizont(int, int, int);
	void VisualVertical(int, int, int);
};