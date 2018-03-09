#include "Board.h"

Board::Board()
{
	for (int k = 0, j = 2; k < 8, j < 26; k++, j += 3)
	{
		vector<Box*> temp;
		for (int i = 2; i < 34; i += 4)
		{
			temp.push_back(new Box(i, j));
		}
		vect.push_back(temp);
	}
}

void Board::StartBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Getvect()[i][j]->GetSupervar())
				Getvect()[i][j]->SetSupervar(4);
		}
	}
}

void Board::newBoard(int lvl)
{
	for (int i = 0; i < 8; i++)
	{
		vect[i].clear();
	}
	vect.clear();
	for (int k = 0, j = 2; k < 8, j < 26; k++, j += 3)
	{
		vector<Box*> temp;
		for (int i = 2; i < 34; i += 4)
		{
			temp.push_back(new Box(i, j, lvl));
		}
		vect.push_back(temp);
	}
}

bool Board::CompareBox(int index1_choise, int index2_choise, int index1_edit, int index2_edit)
{

		return vect[index1_choise][index2_choise]->GetColor() == vect[index1_edit][index2_edit]->GetColor();
}

void Board::PrintBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			vect[i][j]->Print();
		}
	}
}

void Board::PrintGrani()
{
	WriteChar(0, 0, 201);
	WriteChars(1, 0, 205, 33);
	WriteChar(0, 26, 200);
	WriteChar(34, 0, 187);
	WriteChar(34, 26, 188);
	WriteChars(1, 26, 205, 33);
	for (int i = 1; i < 26; i++)
	{
		WriteChar(0, i, 186);
		WriteChar(34, i, 186);

	}

}

vector<vector<Box*>> Board::Getvect()
{
	return vect;
}

bool Board::CheckSwap(int index1_choise, int index2_choise, int index1_edit, int index2_edit)
{

	if (abs(index1_choise - index1_edit) == 1 && index2_choise == index2_edit)
	{
		return true;
	}
	else if (abs(index2_choise - index2_edit) == 1 && index1_choise == index1_edit)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::CheckCombination(int index1_choise, int index2_choise, int index1_edit, int index2_edit)
{
	int up_1 = 1;
	while (index1_edit - up_1 >= 0 && vect[index1_edit - up_1][index2_edit]->GetColor() == vect[index1_edit][index2_edit]->GetColor())
	{
		up_1++;
		if (up_1 > 2)
			return true;
	}
	int down_1 = 1;
	while (index1_edit + down_1 < 8 && vect[index1_edit + down_1][index2_edit]->GetColor() == vect[index1_edit][index2_edit]->GetColor())
	{
		down_1++;
		if (down_1 > 2)
			return true;
	}
	if (up_1 + down_1 > 3)
	{
		return true;
	}
	int left_1 = 1;
	while (index2_edit - left_1 >= 0 && vect[index1_edit][index2_edit - left_1]->GetColor() == vect[index1_edit][index2_edit]->GetColor())
	{
		left_1++;
		if (left_1 > 2)
			return true;
	}
	int right_1 = 1;
	while (index2_edit + right_1 < 8 && vect[index1_edit][index2_edit + right_1]->GetColor() == vect[index1_edit][index2_edit]->GetColor())
	{
		right_1++;
		if (right_1 > 2)
			return true;
	}
	if (left_1 + right_1 > 3)
	{
		return true;
	}

	int up_2 = 1;
	while (index1_choise - up_2 >= 0 && vect[index1_choise - up_2][index2_choise]->GetColor() == vect[index1_choise][index2_choise]->GetColor())
	{
		up_2++;
		if (up_2 > 2)
			return true;
	}
	int down_2 = 1;
	while (index1_choise + down_2 < 8 && vect[index1_choise + down_2][index2_choise]->GetColor() == vect[index1_choise][index2_choise]->GetColor())
	{
		down_2++;
		if (down_2 > 2)
			return true;
	}
	if (up_2 + down_2 > 3)
	{
		return true;
	}
	int left_2 = 1;
	while (index2_choise - left_2 >= 0 && vect[index1_choise][index2_choise - left_2]->GetColor() == vect[index1_choise][index2_choise]->GetColor())
	{
		left_2++;
		if (left_2 > 2)
			return true;
	}
	int right_2 = 1;
	while (index2_choise + right_2 < 8 && vect[index1_choise][index2_choise + right_2]->GetColor() == vect[index1_choise][index2_choise]->GetColor())
	{
		right_2++;
		if (right_2 > 2)
			return true;
	}
	if (left_2 + right_2 > 3)
	{
		return true;
	}
	return false;
}

void Board::VisualHorizont(int info_step, int indexY, int indexX)
{
	for (int step = 0; step != info_step; step++)
	{
		if (indexX + step >= 0 && indexX + step < 8 && indexY >= 0 && indexY < 8)
		{
			vect.data()[indexY][indexX + step]->ChangeColor(Black);
			vect.data()[indexY][indexX + step]->Print();
		}
	}
	Sleep(500);
}

void Board::VisualVertical(int info_step, int indexY, int indexX)
{
	do
	{
		if (indexX >= 0 && indexX < 8 && indexY >= 0 && indexY < 8)
		{
			vect.data()[indexY + info_step - 1][indexX]->ChangeColor(Black);
			vect.data()[indexY + info_step - 1][indexX]->Print();
		}
		info_step--;
	} while (info_step != 0);
	Sleep(500);
}