#include "Player.h"
#include "Level.h"

Player::Player()
{
	WriteStr(40, 0, "Enter player name: ");
	name = new char;
	cin >> name;
	score = 0;
}

void Player::PrintPlayer()
{
	ChangeTextAttr(40, 0, Black, Black, 25);
	WriteStr(40, 0, "Player name: ");
	cout << name;
	ChangeTextAttr(47, 1, Black, Black, 25);
	WriteStr(40, 1, "Score: ");
	cout << score;
}

void Player::ChangeScore(int number)
{
	score += number;
}

void Player::PrintScore()
{
	ChangeTextAttr(47, 1, Black, Black, 25);
	GotoXY(47, 1);
	cout << score;
}

void Player::ResetScore()
{
	score = 0;
}

int Player::GetScore()
{
	return score;
}
