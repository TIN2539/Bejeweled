#include <time.h>
#include "ConsoleLib.h"
#include <conio.h>
#include <iostream>
#include "Board.h"
#include "Cursor.h"
#include "Player.h"
#include "Level.h"
#include "Game.h"
#include <fstream>
using namespace std;

const int Esc = 27;
const int Enter = 13;

int main()
{
	ShowCursor(false);
	int key;
	srand((unsigned)time(0));
	Game b;
	b.ForStart();
	do
	{
		key = _getch();
		b.GameProcces(key);
	} while (key != Esc && b.CheckMove());
}