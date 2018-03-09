#include "Box.h"

Box::Box():
	Box(0,0)
{
}

Box::Box(int X, int Y)
{
	pos_box.SetX(X);
	pos_box.SetY(Y);
	color = ConsoleColor(rand() % 7 + 9);
	super_var = 0;
}

Box::Box(int X, int Y, int lvl)
{
	pos_box.SetX(X);
	pos_box.SetY(Y);
	color = ConsoleColor(rand() % (7 + lvl) + (9 - lvl));
	super_var = 0;
}

void Box::Print()
{
	switch (super_var)
	{
	case 1:
		SetColor(Black, color);
		for (int i = 0; i < 2; i++)
		{
			WriteChar(pos_box.GetX(), pos_box.GetY() + i, 17);
			WriteChar(pos_box.GetX() + 1, pos_box.GetY() + i, 18);
			WriteChar(pos_box.GetX() + 2, pos_box.GetY() + i, 16);
		}
		SetColor(White, Black);
		break;
	case 2:
		SetColor(Black, color);
		for (int i = 0; i < 2; i++)
		{
			WriteChar(pos_box.GetX(), pos_box.GetY() + i, 4);
			WriteChar(pos_box.GetX() + 1, pos_box.GetY() + i, ' ');
			WriteChar(pos_box.GetX() + 2, pos_box.GetY() + i, 4);
		}
		SetColor(White, Black);
		break;
	default:
		SetColor(Black, color);
		for (int i = 0; i < 2; i++)
		{
			WriteChars(pos_box.GetX(), pos_box.GetY() + i, ' ', 3);
		}
		SetColor(White, Black);
		break;
		/*SetColor(Black, color);
		for (int i = 0; i < 2; i++)
		{
			WriteChar(pos_box.GetX(), pos_box.GetY() + i, 1);
			WriteChar(pos_box.GetX() + 1, pos_box.GetY() + i, ' ');
			WriteChar(pos_box.GetX() + 2, pos_box.GetY() + i, 1);
		}
		SetColor(White, Black);
		break;*/
	}
}

ConsoleColor Box::GetColor()
{
	return color;
}

void Box::ChangeColor(ConsoleColor src_clr)
{
	color = src_clr;
}

void Box::SetSupervar(int k)
{
	switch (k)
	{
	case 4:
		super_var = 0;
		break;
	case 5:
		super_var = 1;
		break;
	case 6:
		super_var = 2;
		break;
	default:
		super_var = 0;
		break;
	}
}
int Box::GetSupervar()
{
	return super_var;
}
