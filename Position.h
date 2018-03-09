#pragma once

class Position
{
protected:
	int x, y;
public:
	Position() {};
	Position(int, int);
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
};