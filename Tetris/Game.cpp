#include "stdafx.h"
#include "Tetris.h"
#include "TetrisDlg.h"
#include "AchieveDlg.h"
#include "afxdialogex.h"
#include "ChooseDlg.h"
#include "Game.h"
#include <fstream>

Game::Game(int pa, int di)
	:pattern(pa), difficu(di)
{
	memset(bigCanvas, 0, sizeof(bigCanvas));
	memset(smallCanvas, 0, sizeof(smallCanvas));
	srand((unsigned int)time(NULL));
	box = new Box(rand() % 7 + 1);
	srand(rand());
	nextBox = new Box(rand() % 7 + 1);
	totalLines = 0;
	baseSpeed = 1000;
	deathNum = GetDeathNum();
}

Game::~Game()
{
}

int Game::DeleteLines()
{
	int lines = 0;

	for (int i = CANVAS_HEIGHT; i > 0; i--)
		while (CanDeleteLine(i))
		{
			DeleteLine(i);
			lines++;
		}

	return lines;
}
void Game::DeleteLine(int index)
{
	for (int i = index; i > 0; i--)
		for (int j = 0; j < CANVAS_WIDTH; j++)
			bigCanvas[i][j] = bigCanvas[i - 1][j];

	for (int j = 0; j < CANVAS_WIDTH; j++)
		bigCanvas[0][j] = 0;

}

BOOL Game::CanDeleteLine(int index)
{
	int count = 0;

	for (int i = 0; i < CANVAS_WIDTH; i++)
		if (bigCanvas[index][i] == 1)
			count++;
	return count == CANVAS_WIDTH;
}
int Game::GetDeathNum()
{
	fstream file;
	file.open("DeathNum.txt", ios::in);
	if (!file)
		MessageBox(L"file not founded");
	int pos = 0;
	while (!file.eof())//是否到文件结尾
	{
		file >> deathNum;
		pos++;
		if (pos >= 100)
			break;
	}
	file.close();
	return deathNum;
}

void Game::SetDeathNum(int num)
{
	fstream fs;
	fs.open("DeathNum.txt", ios_base::out);
	
	fs << num;
	fs.close();
}
void Game::CalScore(int line)
{
	if (line == 1)
		scores += 5;
	if (line == 2)
		scores += 8;
	if (line == 3)
		scores += 10;
	if (line == 4)
		scores += 15;
}

BOOL Game::GameOver()
{
	return 0;
}

BOOL Game::CanMoveDown()
{
	int cnt1 = 4, cnt2 = 0, x = box->Pos_x, y = box->Pos_y + 1;
	int tmp[20][9];

	// 复制一个副本，统计原有方块数+box中的块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
		{
			tmp[i][j] = bigCanvas[i][j];
			cnt1 += tmp[i][j];
		}

	// 假设发生变换
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i + y >= 0 &&
				i + y < CANVAS_HEIGHT  &&
				j + x >= 0 &&
				j + x < CANVAS_WIDTH   &&
				box->_data[i][j])
				tmp[(i + y)][j + x] = 1;
		}

	// 统计变换后方块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
			cnt2 += tmp[i][j];

	return cnt2 == cnt1;
}

BOOL Game::CanMoveLeft()
{
	int cnt1 = 4, cnt2 = 0, x = box->Pos_x - 1, y = box->Pos_y;
	int tmp[20][9];

	// 复制一个副本，统计原有方块数+box中的块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
		{
			tmp[i][j] = bigCanvas[i][j];
			cnt1 += tmp[i][j];
		}

	// 假设发生变换
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i + y >= 0 &&
				i + y < CANVAS_HEIGHT  &&
				j + x >= 0 &&
				j + x < CANVAS_WIDTH   &&
				box->_data[i][j])
				tmp[(i + y)][j + x] = 1;
		}

	// 统计变换后方块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
			cnt2 += tmp[i][j];

	return cnt2 == cnt1;
}

BOOL Game::CanMoveRight()
{
	int cnt1 = 4, cnt2 = 0, x = box->Pos_x + 1, y = box->Pos_y;
	int tmp[20][9];

	// 复制一个副本，统计原有方块数+box中的块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
		{
			tmp[i][j] = bigCanvas[i][j];
			cnt1 += tmp[i][j];
		}

	// 假设发生变换
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i + y >= 0 &&
				i + y < CANVAS_HEIGHT  &&
				j + x >= 0 &&
				j + x < CANVAS_WIDTH   &&
				box->_data[i][j])
				tmp[(i + y)][j + x] = 1;
		}

	// 统计变换后方块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
			cnt2 += tmp[i][j];

	return cnt2 == cnt1;
}

BOOL Game::CanRoll()
{
	int cnt1 = 4, cnt2 = 0, x = box->Pos_x, y = box->Pos_y;
	int tmp[20][9];
	int *rollData = box->GetRollData();

	// 复制一个副本，统计原有方块数+box中的块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
		{
			tmp[i][j] = bigCanvas[i][j];
			cnt1 += tmp[i][j];
		}

	// 假设发生变换
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i + y >= 0 &&
				i + y < CANVAS_HEIGHT  &&
				j + x >= 0 &&
				j + x < CANVAS_WIDTH   &&
				rollData[i * 4 + j])
				tmp[(i + y)][j + x] = 1;
		}

	// 统计变换后方块数
	for (int i = 0; i < CANVAS_HEIGHT; i++)
		for (int j = 0; j < CANVAS_WIDTH; j++)
			cnt2 += tmp[i][j];

	return cnt2 == cnt1;
}

void Game::Roll()
{
	int tmp[4][4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			tmp[i][j] = box->_data[i][j];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			box->_data[i][j] = tmp[j][3 - i];
}

void Game::MoveDown()
{
	box->Pos_y++;
}

void Game::MoveLeft()
{
	box->Pos_x--;
}

void Game::MoveRight()
{
	box->Pos_x++;
}

void Game::start()
{
	isRun = TRUE;
}

void Game::PauseOrContinue()
{
	if (isRun)
	{
		isRun = FALSE;
	}
	else
	{
		isRun = TRUE;
	}
}

BOOL Game::IsDead()
{
	int cnt1 = 4, cnt2 = 0, x = (CANVAS_WIDTH - 4) / 2, y = 0;
	int tmp[20][9];

	// 复制一个副本，统计原有方块数+tool中的块数
	for (int i = 0; i<CANVAS_HEIGHT; i++)
		for (int j = 0; j<CANVAS_WIDTH; j++)
		{
			tmp[i][j] = bigCanvas[i][j];
			cnt1 += tmp[i][j];
		}

	// 假设发生变换
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
		{
			if (i + y >= 0 &&
				i + y<CANVAS_HEIGHT  &&
				j + x >= 0 &&
				j + x<CANVAS_WIDTH   &&
				nextBox->_data[i][j])
				tmp[(i + y)][j + x] = 1;
		}

	// 统计变换后方块数
	for (int i = 0; i<CANVAS_HEIGHT; i++)
		for (int j = 0; j<CANVAS_WIDTH; j++)
			cnt2 += tmp[i][j];

	return cnt2 != cnt1;
}
void Game::AddBox(int choose)
{
	memset(canvas, 0, sizeof(canvas));
	if (choose == 1)
	{
		for (int i = 0; i < CANVAS_HEIGHT; i++)
			for (int j = 0; j < CANVAS_WIDTH; j++)
				canvas[i][j] = bigCanvas[i][j];

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (
					box->_data[i][j])
					canvas[i + box->Pos_y][j + box->Pos_x] = 1;
			}
	}
	else
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (
					box->_data[i][j])
					bigCanvas[i + box->Pos_y][j + box->Pos_x] = 1;
			}
	}
}
BOOL Game::UpdateDifficu(int tmpLines)
{
	totalLines += tmpLines;
	if ((totalLines % 10 == 0) && (difficu < 9) && totalLines > 0)
	{
		difficu++;
		return TRUE;
	}
	return FALSE;
}