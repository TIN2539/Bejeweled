#include "Cursor.h"

Cursor::Cursor()
{
	choise = false;
	curs_pos.SetX(1);
	curs_pos.SetY(1);
}

bool Cursor::GetChoise()
{
	return choise;
}

void Cursor::SetChoise(bool src_choise)
{
	choise = src_choise;
}

void Cursor::PrintCursorDefault()
{
	CleanCursor();
	WriteChar(curs_pos.GetX(), curs_pos.GetY(), 218); //218 левый верх
	WriteChar(curs_pos.GetX(), curs_pos.GetY() + 3, 192); //192 левый низ
	WriteChar(curs_pos.GetX() + 4, curs_pos.GetY(), 191); //191 правый верх
	WriteChar(curs_pos.GetX() + 4, curs_pos.GetY() + 3, 217); //217 правый низ
}

void Cursor::PrintCursorChoise()
{
	CleanCursor();
	for (int i = 0; i < 3; i++)
	{
		WriteChar(curs_pos.GetX(), curs_pos.GetY() + i, '|');
		WriteChar(curs_pos.GetX() + 4, curs_pos.GetY() + i, '|');
	}
	WriteChars(curs_pos.GetX(), curs_pos.GetY(), '-', 5);
	WriteChars(curs_pos.GetX(), curs_pos.GetY() + 3, '-', 5);
}

void Cursor::CleanCursor()
{
	SetColor(Black, Black);
	for (int i = 0; i < 3; i++)
	{
		WriteChar(curs_pos.GetX(), curs_pos.GetY() + i, '|');
		WriteChar(curs_pos.GetX() + 4, curs_pos.GetY() + i, '|');
	}
	WriteChars(curs_pos.GetX(), curs_pos.GetY(), '-', 5);
	WriteChars(curs_pos.GetX(), curs_pos.GetY() + 3, '-', 5);
	SetColor(White, Black);
}

Position Cursor::Getpos()
{
	return curs_pos;
}

void Cursor::MoveCursor(int key)
{
	switch (key)
	{
	case 72:		// Up
		if (curs_pos.GetY() == 1)
			break;
		else
		{
			curs_pos.SetY(curs_pos.GetY() - 3);
			break;
		}
	case 75:		//Left
		if (curs_pos.GetX() == 1)
			break;
		else
		{
			curs_pos.SetX(curs_pos.GetX() - 4);
			break;
		}
	case 77:		//Right
		if (curs_pos.GetX() >= 26)
			break;
		else
		{
			curs_pos.SetX(curs_pos.GetX() + 4);
			break;
		}
	case 80:		// Down
		if (curs_pos.GetY() >= 21)
			break;
		else
		{
			curs_pos.SetY(curs_pos.GetY() + 3);
			break;
		}
	}
}