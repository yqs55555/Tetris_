#include "stdafx.h"
#include "Tetris.h"
#include "TetrisDlg.h"
#include "AchieveDlg.h"
#include "afxdialogex.h"
#include "ChooseDlg.h"
#include "Game.h"

Game::Game(int pa,int di)
	:pattern(pa),difficu(di)
{
	memset(bigCanvas, 0, sizeof(bigCanvas));
	memset(smallCanvas, 0, sizeof(smallCanvas));
	srand((unsigned int)time(NULL));
	box = new Box(rand() % 7 + 1);
	srand(rand());
	nextBox = new Box(rand() % 7 + 1);
}


Game::~Game()
{
}

int Game::DeleteLines()
{
	for (int i = CANVAS_HEIGHT; i > 0; i--)
		while (CanDeleteLine(i))
			DeleteLine(i);

	return 0;
}
void Game::DeleteLine(int index)
{
	for (int i = index; i>0; i--)
		for (int j = 0; j<CANVAS_WIDTH; j++)
			bigCanvas[i][j] = bigCanvas[i - 1][j];

	for (int j = 0; j<CANVAS_WIDTH; j++)
		bigCanvas[0][j] = 0;

}

BOOL Game::CanDeleteLine(int index)
{
	int count = 0;

	for (int i = 0; i<CANVAS_WIDTH; i++)
		if (bigCanvas[index][i] == 1)
			count++;
	return count == CANVAS_WIDTH;
}
void Game::CalScore(int line)
{
}

BOOL Game::GameOver()
{
	return 0;
}

BOOL Game::CanMoveDown()
{
	return Crash(box->Pos_x,box->Pos_y + 1);
}

BOOL Game::CanMoveLeft()
{
	return Crash(box->Pos_x - 1,box->Pos_y);
}

BOOL Game::CanMoveRight()
{
	return Crash(box->Pos_x + 1,box->Pos_y);
}

BOOL Game::CanRoll()
{
	return Crash(box->Pos_x, box->Pos_y);
}

void Game::Roll()
{
	int tmp[4][4];

	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			tmp[i][j] = box->_data[i][j];

	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
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

BOOL Game::Crash(int x,int y)
{
	int cnt1 = 4, cnt2 = 0;
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
				box->_data[i][j])
				tmp[i + y][j + x] = 1;
		}

	// 统计变换后方块数
	for (int i = 0; i<CANVAS_HEIGHT; i++)
		for (int j = 0; j<CANVAS_WIDTH; j++)
			cnt2 += tmp[i][j];

	return cnt2 == cnt1;
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
				tmp[i + y][j + x] = 1;
		}

	// 统计变换后方块数
	for (int i = 0; i<CANVAS_HEIGHT; i++)
		for (int j = 0; j<CANVAS_WIDTH; j++)
			cnt2 += tmp[i][j];

	return cnt2 != cnt1;
}
void Game::AddBox()
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
		{
			if (i + box->Pos_y >= 0 &&
				i + box->Pos_y<CANVAS_HEIGHT  &&
				j + box->Pos_x >= 0 &&
				j + box->Pos_x<CANVAS_WIDTH   &&
				box->_data[i][j])
				bigCanvas[(i + box->Pos_y - 1)][j + box->Pos_x -1] = 1;
		}
}