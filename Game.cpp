#include "Game.h"

void Game::ForStart()
{
	do {} while (RemoveBox());
	pl.ResetScore();
	pl_board.Getvect()[1][2]->ChangeColor(Yellow);
	pl_board.Getvect()[1][3]->ChangeColor(Yellow);
	pl_board.Getvect()[1][5]->ChangeColor(Yellow);
	pl_board.Getvect()[1][6]->ChangeColor(Yellow);
	pl_board.Getvect()[2][4]->ChangeColor(Yellow);

	Print();
}

void Game::Print()
{
	pl.PrintPlayer();
	pl_board.PrintBoard();
	pl_board.PrintGrani();
	pl_curs.PrintCursorDefault();
	pl_lvl.PrintLvl();
}

void Game::RemoveSomeBox(int index1_choise, int index2_choise, int index1_edit, int index2_edit)
{
	bool checksuper = false;
	int up_1 = 1, down_1 = 1, left_1 = 1, right_1 = 1;
	int up_2 = 1, down_2 = 1, left_2 = 1, right_2 = 1;

	while (index1_edit - up_1 >= 0 && pl_board.CompareBox(index1_edit - up_1, index2_edit, index1_edit, index2_edit))
	{
		up_1++;
	}
	while (index1_edit + down_1 < 8 && pl_board.CompareBox(index1_edit + down_1, index2_edit, index1_edit, index2_edit))
	{
		down_1++;
	}
	while (index2_edit - left_1 >= 0 && pl_board.CompareBox(index1_edit, index2_edit - left_1, index1_edit, index2_edit))
	{
		left_1++;
	}
	while (index2_edit + right_1 < 8 && pl_board.CompareBox(index1_edit, index2_edit + right_1, index1_edit, index2_edit))
	{
		right_1++;
	}

	while (index1_choise - up_2 >= 0 && pl_board.CompareBox(index1_choise - up_2, index2_choise, index1_choise, index2_choise))
	{
		up_2++;
	}
	while (index1_choise + down_2 < 8 && pl_board.CompareBox(index1_choise + down_2, index2_choise, index1_choise, index2_choise))
	{
		down_2++;
	}
	while (index2_choise - left_2 >= 0 && pl_board.CompareBox(index1_choise, index2_choise - left_2, index1_choise, index2_choise))
	{
		left_2++;
	}
	while (index2_choise + right_2 < 8 && pl_board.CompareBox(index1_choise, index2_choise + right_2, index1_choise, index2_choise))
	{
		right_2++;
	}

	if (up_1 + down_1 == 4)
	{
		int q = 1;
		int home = index1_edit - up_1 + 1;
		int step = up_1 + down_1 - 2;
		for (int i = 0; i < up_1 + down_1 - 1; i++)
		{
			if (pl_board.Getvect()[home + i][index2_edit]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(home + i, index2_edit);
			}
		}
		if (!checksuper)
		{
			pl.ChangeScore(step + 1);
			pl_board.VisualVertical(step + 1, home, index2_edit);
			do
			{
				if (home - q >= 0)
				{
					pl_board.Getvect()[home + step][index2_edit]->ChangeColor(pl_board.Getvect()[home - q][index2_edit]->GetColor());
					pl_board.Getvect()[home + step][index2_edit]->SetSupervar(pl_board.Getvect()[home - q][index2_edit]->GetSupervar() + 4);

				}
				else
				{
					ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
					pl_board.Getvect().data()[home + step][index2_edit]->ChangeColor(temp);
				}
				q++;
				step--;
			} while (home + step >= 0);
		}
	}
	else if (up_1 + down_1 > 4)
	{
		int q = 1;
		int home = index1_edit - up_1 + 1;
		int step = up_1 + down_1 - 3;
		for (int i = 0; i < up_1 + down_1 - 1; i++)
		{
			if (pl_board.Getvect().data()[home + i][index2_edit]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(home + i, index2_edit);
			}
		}
		if (!checksuper)
		{
			ConsoleColor choise = pl_board.Getvect()[index1_edit][index2_edit]->GetColor();
			pl_board.Getvect()[home + step + 1][index2_edit]->SetSupervar(up_1 + down_1);
			pl.ChangeScore(step + 2);
			pl_board.VisualVertical(step + 1, home, index2_edit);
			do
			{
				if (home - q >= 0)
				{
					pl_board.Getvect()[home + step][index2_edit]->ChangeColor(pl_board.Getvect()[home - q][index2_edit]->GetColor());
					pl_board.Getvect()[home + step][index2_edit]->SetSupervar(pl_board.Getvect()[home - q][index2_edit]->GetSupervar() + 4);
				}
				else
				{
					ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
					pl_board.Getvect()[home + step][index2_edit]->ChangeColor(temp);
				}
				q++;
				step--;
			} while (home + step >= 0);
		}
	}
	if (left_1 + right_1 == 4)
	{
		checksuper = false;
		int step = left_1 + right_1 - 1;
		int q = 1;
		int home = index2_edit - left_1 + 1;
		for (int i = 0; i < left_1 + right_1 - 1; i++)
		{
			if (pl_board.Getvect()[index1_edit][home + i]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(index1_edit, home + i);
			}
		}
		if (!checksuper)
		{
			pl.ChangeScore(step);
			pl_board.VisualHorizont(step, index1_edit, home);
			for (int a = index1_edit; a >= 0; a--)
			{
				int n = 0;
				do
				{
					if (a != 0)
					{
						pl_board.Getvect()[a][home + n]->ChangeColor(pl_board.Getvect()[a - 1][home + n]->GetColor());
						pl_board.Getvect()[a][home + n]->SetSupervar(pl_board.Getvect()[a - 1][home + n]->GetSupervar() + 4);
					}
					else
					{
						ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
						pl_board.Getvect()[0][home + n]->ChangeColor(temp);
					}
					n++;
				} while (n != step);
			}
		}
	}
	else if (left_1 + right_1 > 4)
	{
		checksuper = false;
		int step = left_1 + right_1 - 1;
		int q = 1;
		int home = index2_edit - left_1 + 1;
		for (int i = 0; i < left_1 + right_1 - 1; i++)
		{
			if (pl_board.Getvect()[index1_edit][home + i]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(index1_edit, home + i);
			}
		}
		if (!checksuper)
		{
			ConsoleColor choise = pl_board.Getvect()[index1_edit][index2_edit]->GetColor();
			pl.ChangeScore(step);
			pl_board.VisualHorizont(step, index1_edit, home);
			for (int a = index1_edit; a >= 0; a--)
			{
				int n = 0;
				do
				{
					if (a != 0)
					{
						pl_board.Getvect()[a][home + n]->ChangeColor(pl_board.Getvect()[a - 1][home + n]->GetColor());
						pl_board.Getvect()[a][home + n]->SetSupervar(pl_board.Getvect()[a - 1][home + n]->GetSupervar() + 4);
					}
					else
					{
						ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
						pl_board.Getvect()[0][home + n]->ChangeColor(temp);
					}
					n++;
				} while (n != step);
			}
			pl_board.Getvect()[index1_edit][index2_edit]->SetSupervar(left_1 + right_1);
			pl_board.Getvect()[index1_edit][index2_edit]->ChangeColor(choise);
		}
	}
	if (up_2 + down_2 == 4)
	{
		checksuper = false;
		int q = 1;
		int home = index1_choise - up_2 + 1;
		int step = up_2 + down_2 - 2;
		for (int i = 0; i < up_2 + down_2 - 1; i++)
		{
			if (pl_board.Getvect()[home + i][index2_choise]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(home + i, index2_choise);
			}
		}
		if (!checksuper)
		{
			pl.ChangeScore(step + 1);
			pl_board.VisualVertical(step + 1, home, index2_choise);
			do
			{
				if (home - q >= 0)
				{
					pl_board.Getvect()[home + step][index2_choise]->ChangeColor(pl_board.Getvect()[home - q][index2_choise]->GetColor());
					pl_board.Getvect()[home + step][index2_choise]->SetSupervar(pl_board.Getvect()[home - q][index2_choise]->GetSupervar() + 4);
				}
				else
				{
					ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
					pl_board.Getvect()[home + step][index2_choise]->ChangeColor(temp);
				}
				q++;
				step--;
			} while (home + step >= 0);
		}
	}
	else if (up_2 + down_2 > 4)
	{
		ConsoleColor choise = pl_board.Getvect()[index1_choise][index2_choise]->GetColor();
		checksuper = false;
		int q = 1;
		int home = index1_choise - up_2 + 1;
		int step = up_2 + down_2 - 3;
		for (int i = 0; i < up_2 + down_2 - 1; i++)
		{
			if (pl_board.Getvect()[home + i][index2_choise]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(home + i, index2_choise);
			}
		}
		if (!checksuper)
		{
			pl_board.Getvect()[home + step + 1][index2_choise]->SetSupervar(up_2 + down_2);
			pl.ChangeScore(step + 2);
			pl_board.VisualVertical(step + 1, home, index2_choise);
			do
			{
				if (home - q >= 0)
				{
					pl_board.Getvect()[home + step][index2_choise]->ChangeColor(pl_board.Getvect()[home - q][index2_choise]->GetColor());
					pl_board.Getvect()[home + step][index2_choise]->SetSupervar(pl_board.Getvect()[home - q][index2_choise]->GetSupervar() + 4);
				}
				else
				{
					ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
					pl_board.Getvect()[home + step][index2_choise]->ChangeColor(temp);
				}
				q++;
				step--;
			} while (home + step >= 0);
		}
	}
	if (left_2 + right_2 == 4)
	{
		checksuper = false;
		int step = left_2 + right_2 - 1;
		int q = 1;
		int home = index2_choise - left_2 + 1;
		for (int i = 0; i < left_2 + right_2 - 1; i++)
		{
			if (pl_board.Getvect()[index1_choise][home + i]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(index1_choise, home + i);
			}
		}
		if (!checksuper)
		{
			pl.ChangeScore(step);
			pl_board.VisualHorizont(step, index1_choise, home);
			for (int a = index1_choise; a >= 0; a--)
			{
				int n = 0;
				do
				{
					if (a != 0)
					{
						pl_board.Getvect()[a][home + n]->ChangeColor(pl_board.Getvect()[a - 1][home + n]->GetColor());
						pl_board.Getvect()[a][home + n]->SetSupervar(pl_board.Getvect()[a - 1][home + n]->GetSupervar() + 4);
					}
					else
					{
						ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
						pl_board.Getvect()[0][home + n]->ChangeColor(temp);
					}
					n++;
				} while (n != step);
			}

		}
	}
	else if (left_2 + right_2 > 4)
	{
		int step = left_2 + right_2 - 1;
		int q = 1;
		int home = index2_choise - left_2 + 1;
		for (int i = 0; i < left_2 + right_2 - 1; i++)
		{
			if (pl_board.Getvect()[index1_choise][home + i]->GetSupervar())
			{
				checksuper = true;
				SuperRemove(index1_choise, home + i);
			}
		}
		if (!checksuper)
		{
			ConsoleColor choise = pl_board.Getvect()[index1_choise][index2_choise]->GetColor();
			pl.ChangeScore(step);
			pl_board.VisualHorizont(step, index1_choise, home);
			for (int a = index1_choise; a >= 0; a--)
			{
				int n = 0;
				do
				{
					if (a != 0)
					{
						pl_board.Getvect()[a][home + n]->ChangeColor(pl_board.Getvect()[a - 1][home + n]->GetColor());
						pl_board.Getvect()[a][home + n]->SetSupervar(pl_board.Getvect()[a - 1][home + n]->GetSupervar() + 4);
					}
					else
					{
						ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
						pl_board.Getvect()[0][home + n]->ChangeColor(temp);
					}
					n++;
				} while (n != step);
			}
			pl_board.Getvect()[index1_choise][index2_choise]->ChangeColor(choise);
			pl_board.Getvect()[index1_choise][index2_choise]->SetSupervar(left_2 + right_2);
		}
	}
	do {} while (RemoveBox());
}

bool Game::RemoveBox()
{
	bool check = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int k = 1;
			while (j + k < 8 && pl_board.CompareBox(i, j, i, j + k))
			{
				k++;
			}
			if (k > 2)
			{
				check = true;
				pl.ChangeScore(k);
				pl_board.VisualHorizont(k, i, j);
				for (int a = i; a >= 0; a--)
				{
					int step = 0;
					do
					{
						if (a != 0 && j + step < 8)
						{
							pl_board.Getvect()[a][j + step]->ChangeColor(pl_board.Getvect()[a - 1][j + step]->GetColor());
							pl_board.Getvect()[a][j + step]->SetSupervar(pl_board.Getvect()[a - 1][j + step]->GetSupervar() + 4);
						}
						else if (j + step < 8)
						{
							ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
							pl_board.Getvect()[0][j + step]->ChangeColor(temp);
						}
						step++;
					} while (step != k);
				}
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int k = 1;
			while (j + k < 8 && pl_board.CompareBox(j, i, j + k, i))
			{
				k++;
			}
			if (k > 2)
			{
				check = true;
				pl.ChangeScore(k);
				pl_board.VisualVertical(k, j, i);
				int q = 1;
				do
				{
					if (j - q >= 0 && j + k - 1 < 8)
					{
						pl_board.Getvect()[j + k - 1][i]->ChangeColor(pl_board.Getvect()[j - q][i]->GetColor());
						pl_board.Getvect()[j + k - 1][i]->SetSupervar(pl_board.Getvect()[j - q][i]->GetSupervar() + 4);
					}
					else if (j + k - 1 < 8)
					{
						ConsoleColor temp = ConsoleColor(rand() % 7 + 9);
						pl_board.Getvect()[j + k - 1][i]->ChangeColor(temp);
					}
					q++;
					k--;
				} while (j + k - 1 >= 0);
			}
		}
	}
	return check;
}

void Game::SuperRemove(int indexY, int indexX)
{
	int k = -3;
	int i = 2;
	switch (pl_board.Getvect()[indexY][indexX]->GetSupervar())
	{
	case 1:
		pl.ChangeScore(63);
		pl_board.VisualHorizont(8, indexY, 0);
		pl_board.VisualVertical(8, 0, indexX);
		pl_board.Getvect()[indexY][indexX]->SetSupervar(4);
		for (int i = 0; i < 8; i++)
		{
			pl_board.Getvect()[i][indexX]->ChangeColor(ConsoleColor(rand() % 7 + 9));
			pl_board.Getvect()[i][indexX]->Print();
			for (int j = indexY; j != 0; j--)
			{
				pl_board.Getvect()[j][i]->ChangeColor(pl_board.Getvect()[j - 1][i]->GetColor());
				pl_board.Getvect()[j][i]->SetSupervar(pl_board.Getvect()[j - 1][i]->GetSupervar() + 4);
				pl_board.Getvect()[j][i]->Print();
			}
		}
		for (int i = 0; i < 8; i++)
		{
			pl_board.Getvect()[0][i]->ChangeColor(ConsoleColor(rand() % 7 + 9));
			pl_board.Getvect()[0][i]->Print();
		}
		for (int i = 0; i < 8; i++)
		{
			if (pl_board.Getvect()[i][indexX]->GetSupervar())
			{
				SuperRemove(i, indexX);
			}
			if (pl_board.Getvect()[indexY][i]->GetSupervar())
			{
				SuperRemove(indexY, i);
			}
		}
		break;
	case 2:
		pl.ChangeScore(25);
		for (int i = -2; i < 3; i++)
		{
			pl_board.VisualHorizont(5, indexY + i, indexX - 2);
		}
		pl_board.Getvect()[indexY][indexX]->SetSupervar(4);
		for (int i = -2; i < 3; i++)
		{
			for (int j = -2; j < 3; j++)
			{
				if (indexY + i >= 0 && indexY + i < 8 && indexX + j >= 0 && indexX + j < 8 && pl_board.Getvect()[indexY + i][indexX + j]->GetSupervar() != 0)
				{
					SuperRemove(indexY + i, indexX + j);
				}
			}
		}
		do
		{
			for (int j = -2; j < 3; j++)
			{
				if (indexY + i >= 0 && indexY + i < 8 && indexX + j >= 0 && indexX + j < 8 && indexY + k >= 0 && indexY + k < 8)
				{
					pl_board.Getvect()[indexY + i][indexX + j]->ChangeColor(pl_board.Getvect()[indexY + k][indexX + j]->GetColor());
					pl_board.Getvect()[indexY + i][indexX + j]->SetSupervar(pl_board.Getvect()[indexY + k][indexX + j]->GetSupervar() + 4);
					pl_board.Getvect()[indexY + i][indexX + j]->Print();
				}
				else if (indexX + j >= 0 && indexX + j < 8 && indexY + i < 8)
				{
					pl_board.Getvect()[indexY + i][indexX + j]->ChangeColor(ConsoleColor(rand() % 7 + 9));
					pl_board.Getvect()[indexY + i][indexX + j]->Print();
				}
				else if (indexY + i > 7)
				{
					i--;
					break;
				}
				if (j == 2)
				{
					i--;
					k--;
				}
			}
		} while (indexY + i + 1 != 0);
		break;
	/*case 3:
		ConsoleColor choise = pl_board.Getvect()[indexY][indexX]->GetColor();
		pl_board.Getvect()[indexY][indexX]->SetSupervar(4);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (pl_board.Getvect()[i][j]->GetColor() == choise)
				{
					pl_board.Getvect()[i][j]->ChangeColor(Black);
					pl.ChangeScore(1);
					pl_board.Getvect()[i][j]->Print();
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (!pl_board.Getvect()[i][j]->GetSupervar() || pl_board.Getvect()[i][j]->GetColor() == Black)
				{
					SuperRemove(i, j);
				}
			}
		}
		Sleep(500);

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (pl_board.Getvect()[i][j]->GetColor() == Black)
				{
					int k = 0;
					do
					{
						if (i - k - 1 >= 0)
						{
							pl_board.Getvect()[i - k][j]->ChangeColor(pl_board.Getvect()[i - k - 1][j]->GetColor());
							pl_board.Getvect()[i - k][j]->SetSupervar(pl_board.Getvect()[i - k - 1][j]->GetSupervar() + 4);
						}
						else
						{
							pl_board.Getvect()[i - k][j]->ChangeColor(ConsoleColor(rand() % 7 + 9));
						}
						k++;
					} while (i - k >= 0);
				}
			}
		}*/
	}
}

bool Game::CheckMove()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j + 1 < 8 && pl_board.CompareBox(i, j, i, j + 1))
			{
				if (j + 3 < 8 && pl_board.CompareBox(i, j, i, j + 3))
				{
					return true;
				}
				else if (j + 2 < 8 && i - 1 >= 0 && pl_board.CompareBox(i, j, i - 1, j + 2))
				{
					return true;
				}
				else if (j + 2 < 8 && i + 1 < 8 && pl_board.CompareBox(i, j, i + 1, j + 2))
				{
					return true;
				}
				else if (j - 2 >= 0 && pl_board.CompareBox(i, j,i, j - 2))
				{
					return true;
				}
				else if (j - 1 >= 0 && i - 1 >= 0 && pl_board.CompareBox(i, j, i - 1, j - 1))
				{
					return true;
				}
				else if (j - 1 >= 0 && i + 1 < 8 && pl_board.CompareBox(i, j, i + 1, j - 1))
				{
					return true;
				}
			}
			if (j + 2 < 8 && pl_board.CompareBox(i, j, i, j + 2))
			{
				if (i - 1 >= 0 && j + 1 < 8 && pl_board.CompareBox(i, j, i - 1, j + 1))
				{
					return true;
				}
				else if (i + 1 < 8 && j + 1 < 8 && pl_board.CompareBox(i, j, i + 1, j + 1))
				{
					return true;
				}
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j + 1 < 8 && pl_board.CompareBox(j, i, j + 1, i))
			{
				if (j + 3 < 8 && pl_board.CompareBox(j, i, j + 3, i))
				{
					return true;
				}
				else if (j + 2 < 8 && i + 1 < 8 && pl_board.CompareBox(j, i, j + 2, i + 1))
				{
					return true;
				}
				else if (j + 2 < 8 && i - 1 >= 0 && pl_board.CompareBox(j, i, j + 2, i - 1))
				{
					return true;
				}
				else if (j - 2 >= 0 && pl_board.CompareBox(j, i, j - 2, i))
				{
					return true;
				}
				else if (j - 1 >= 0 && i - 1 >= 0 && pl_board.CompareBox(j, i, j - 1, i - 1))
				{
					return true;
				}
				else if (j - 1 >= 0 && i + 1 < 8 && pl_board.CompareBox(j, i, j - 1, i + 1))
				{
					return true;
				}
			}
			if (j + 2 < 8 && pl_board.CompareBox(j, i, j + 2, i))
			{
				if (j + 1 < 8 && i + 1 < 8 && pl_board.CompareBox(j, i, j + 1, i + 1))
				{
					return true;
				}
				else if (j + 1 < 8 && i - 1 >= 0 && pl_board.CompareBox(j,i, j + 1, i - 1))
				{
					return true;
				}
			}
		}
	}
	ShowCursor(false);
	WriteStr(38, 12, "YOU LOSE!");
	cout << endl;
	return false;
}

void Game::Swap(int indexY1, int indexX1, int indexY2, int indexX2)
{
	Box temp;
	if (pl_board.CheckSwap(indexY1, indexX1, indexY2, indexX2))
	{
		temp = *pl_board.Getvect()[indexY2][indexX2];
		pl_board.Getvect()[indexY2][indexX2]->ChangeColor(pl_board.Getvect()[indexY1][indexX1]->GetColor());
		pl_board.Getvect()[indexY2][indexX2]->SetSupervar(pl_board.Getvect()[indexY1][indexX1]->GetSupervar() + 4);
		pl_board.Getvect()[indexY1][indexX1]->ChangeColor(temp.GetColor());
		pl_board.Getvect()[indexY1][indexX1]->SetSupervar(temp.GetSupervar() + 4);
		pl_board.PrintBoard();
		Sleep(500);
		if (!pl_board.CheckCombination(indexY1, indexX1, indexY2, indexX2))
		{
			pl_board.Getvect()[indexY1][indexX1]->ChangeColor(pl_board.Getvect()[indexY2][indexX2]->GetColor());
			pl_board.Getvect()[indexY1][indexX1]->SetSupervar(pl_board.Getvect()[indexY2][indexX2]->GetSupervar() + 4);
			pl_board.Getvect()[indexY2][indexX2]->ChangeColor(temp.GetColor());
			pl_board.Getvect()[indexY2][indexX2]->SetSupervar(temp.GetSupervar() + 4);
			pl_board.PrintBoard();
			Sleep(500);
		}
		else
		{
			RemoveSomeBox(indexY1, indexX1, indexY2, indexX2);
		}
	}
}

bool Game::CheckWin()
{
	if (pl.GetScore() >= pl_lvl.GetScore_lvl())
	{
		system("cls");
		WriteStr(12, 12, "YOU WIN! FOR THE NEXT LEVEL PRESS ANY KEY...");
		_getch();
		ChangeTextAttr(12, 12, Black, Black, 50);
		pl_lvl.UpLvl();
		pl_board.newBoard(pl_lvl.Getlvl());
		ForStart();
	}
	return true;
}

//void Game::SaveToFile()
//{
//	wofstream out("base.txt", ios::trunc);
//
//	out << pl.GetScore();
//	out << pl_curs.Getpos().GetX();
//	out << pl_curs.Getpos().GetY();
//	for (int i = 0; i < pl_board.Getvect().size(); ++i)
//	{
//		for (int j = 0; j < pl_board.Getvect()[i].size(); ++j)
//		{
//			out << pl_board.Getvect()[i][j];
//		}
//	}
//
//	out << pl_lvl.Getlvl();
//	out << pl_lvl.GetScore_lvl();
//	cout << "Saved!";
//	out.close();
//}
//
//Game Game::LoadFromFile()
//{
//	wifstream in("base.txt");
//
//	if (in) 
//	{
//
//		in.close();
//	}
//}

int indexX1 = 0, indexY1 = 0;
void Game::GameProcces(int key)
{
	Box* temp1;
	int indexX2 = 0, indexY2 = 0;
	if (key == Enter)
	{
		if (!pl_curs.GetChoise())
		{
			indexX1 = (pl_curs.Getpos().GetX() - 1) / 4;
			indexY1 = (pl_curs.Getpos().GetY() - 1) / 3;
			temp1 = pl_board.Getvect()[indexY1][indexX1];
			pl_curs.PrintCursorChoise();
			pl_curs.SetChoise(true);
		}
		else
		{
			indexX2 = (pl_curs.Getpos().GetX() - 1) / 4;
			indexY2 = (pl_curs.Getpos().GetY() - 1) / 3;
			Swap(indexY1, indexX1, indexY2, indexX2);
			pl_board.PrintBoard();
			pl.PrintScore();
			pl_curs.PrintCursorDefault();
			pl_curs.SetChoise(false);
			CheckWin();
		}
	}
	else if (key == 0 || key == 0xE0)
	{
		key = _getch();
		pl_curs.CleanCursor();
		pl_curs.MoveCursor(key);
		if (pl_curs.GetChoise())
		{
			pl_curs.PrintCursorChoise();
		}
		else
		{
			pl_curs.PrintCursorDefault();
		}
	}
}