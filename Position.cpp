#include "Position.h"

Position::Position(int X, int Y)
{
	x = X;
	y = Y;
}

void Position::SetX(int X)
{
	x = X;
}

void Position::SetY(int Y)
{
	y = Y;
}

int Position::GetX()
{
	return x;
}

int Position::GetY()
{
	return y;
}